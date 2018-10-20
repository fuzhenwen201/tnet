#include <stdio.h>
#include <string>

#include <signal.h>

#include "xlogger.h"

#include "address.h"
#include "tcpserver.h"

#include "connection.h"

#include "httpserver.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "httpconnection.h"

using namespace std;
using namespace tnet;
using namespace std::placeholders;


void onHandler(const HttpConnectionPtr_t& conn, const HttpRequest& request)
{
    HttpResponse resp;
    resp.statusCode = 200;
    resp.setContentType("text/html");
    resp.setKeepAlive(true);
    resp.enableDate();

    resp.body.append("Hello World");

    conn->send(resp);
}

int main(int argc, char* argv[])
{
    XLOGGER(argv[0]).StdErr(true).Colour(true).Dir("./logs");
    
    TcpServer s;

    HttpServer httpd(&s);

    httpd.setHttpCallback("/change", std::bind(&onHandler, _1, _2));

    httpd.listen(Address(11181));

    XINFO("start tcp server");

    s.start(4);

    XINFO("stop server");

    return 0;
} 


