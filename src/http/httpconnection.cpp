#include "httpconnection.h"
#include "httpserver.h"
#include "xlogger.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "connection.h"
#include "httpparser.h"

using namespace std;

namespace tnet
{
    size_t HttpConnection::ms_maxHeaderSize = 80 * 1024;
    size_t HttpConnection::ms_maxBodySize = 10 * 1024 * 1024;
    
    static void dummyCallback()
    {}

    HttpConnection::HttpConnection(const ConnectionPtr_t& conn, const RequestCallback_t& callback)
        : HttpParser(HTTP_REQUEST)
        , m_conn(conn)
        , m_callback(callback)
    {
        m_fd = conn->getSockFd();
        m_sendCallback = std::bind(&dummyCallback);
    }

    HttpConnection::~HttpConnection()
    {
        XINFO("httpconnection destroyed");
    }

    void HttpConnection::onConnEvent(const ConnectionPtr_t& conn, ConnEvent event, const void* context)
    {
        HttpConnectionPtr_t httpConn = shared_from_this();

        switch(event)
        {
            case Conn_ReadEvent:
                {
                    const StackBuffer* buf = (const StackBuffer*)context;
                    
                    execute(buf->buffer, buf->count);    
                }
                break;   
            case Conn_WriteCompleteEvent:
                {
                    m_sendCallback();
                    m_sendCallback = std::bind(&dummyCallback);
                }
                break;
            default:
                break; 
        }    
    }

    void HttpConnection::shutDown(int after)
    {
        ConnectionPtr_t conn = m_conn.lock();
        if(conn)
        {
            conn->shutDown(after);    
        }    
    }

    void HttpConnection::send(HttpResponse& resp)
    {
        ConnectionPtr_t conn = m_conn.lock();
        if(!conn)
        {
            return;    
        }    

        conn->send(resp.dump());
    }

    void HttpConnection::send(int statusCode)
    {
        HttpResponse resp;
        resp.statusCode = statusCode;
        
        send(resp);    
    }

    void HttpConnection::send(int statusCode, const string& body)
    {
        HttpResponse resp;
        resp.statusCode = statusCode;
        resp.body = body;
        
        send(resp);    
    }

    void HttpConnection::send(int statusCode, const string& body, const Headers_t& headers)
    {
        HttpResponse resp;
        resp.statusCode = statusCode;
        resp.body = body;
        
        resp.headers = headers;

        send(resp);
    }

    void HttpConnection::send(HttpResponse& resp, const Callback_t& callback)
    {
        m_sendCallback = callback;
        send(resp);    
    }
    
    void HttpConnection::send(int statusCode, const Callback_t& callback)
    {
        m_sendCallback = callback;
        send(statusCode);
    }
        
    void HttpConnection::send(int statusCode, const std::string& body, const Callback_t& callback)
    {
        m_sendCallback = callback;
        send(statusCode, body);
    }
        
    void HttpConnection::send(int statusCode, const std::string& body, const Headers_t& headers, const Callback_t& callback)
    {
        m_sendCallback = callback;
        send(statusCode, body, headers);
    }

    int HttpConnection::onMessageBegin()
    {
        m_request.clear();
        return 0;    
    }

    int HttpConnection::onUrl(const char* at, size_t length)
    {
        m_request.url.append(at, length);    
        return 0;
    }

    int HttpConnection::onHeader(const string& field, const string& value)
    {        
        if(m_parser.nread >= ms_maxHeaderSize)
        {
            m_errorCode = 413;
            return -1;         
        }
    
 
        m_request.headers.insert(make_pair(field, value));    
        return 0;
    }

    int HttpConnection::onBody(const char* at, size_t length)
    {
        if(m_request.body.size() + length > ms_maxBodySize)
        {
            m_errorCode = 413;
            return -1;    
        }

        m_request.body.append(at, length);    
        return 0;
    }

    int HttpConnection::onHeadersComplete()
    {
        m_request.majorVersion = m_parser.http_major;
        m_request.minorVersion = m_parser.http_minor;
        
        m_request.method = (http_method)m_parser.method;

        m_request.parseUrl();

        return 0;    
    }

    int HttpConnection::onMessageComplete()
    {
        if(!m_parser.upgrade)
        {
            m_callback(shared_from_this(), m_request, Request_Complete, 0);    
        }
        return 0;     
    }

    int HttpConnection::onUpgrade(const char* at, size_t length)
    {
        StackBuffer buffer(at, length);
        m_callback(shared_from_this(), m_request, Request_Upgrade, &buffer);
        return 0;    
    }

    int HttpConnection::onError(const HttpError& error)
    {
        m_callback(shared_from_this(), m_request, Request_Error, (void*)&error);
        return 0;    
    }

}
