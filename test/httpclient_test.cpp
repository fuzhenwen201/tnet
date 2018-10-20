#include <iostream>

#include "httpclient.h"

#include "httprequest.h"
#include "httpresponse.h"
#include "ioloop.h"
#include "xlogger.h"

using namespace std;
using namespace tnet;

void onResponse(IOLoop* loop, const HttpResponse& resp)
{
   // cout << resp.statusCode << endl;

    Headers_t::const_iterator iter = resp.headers.begin();

    while(iter != resp.headers.end())
    {
        cout << iter->first << ": " << iter->second << endl;
        ++iter;
    }

    //cout << resp.body.size() << endl << endl;

    loop->stop();
}

int main()
{
    IOLoop loop;

    HttpClientPtr_t client = std::make_shared<HttpClient>(&loop);
    HttpResponse resp = {};
    //Headers_t head = {};
    //head.insert(std::pair<std::string,std::string>("Cookie","__cfduid=dc3a79f884142556c8bc0378e95214e2c1539921839"));
    //head.insert(std::pair<std::string,std::string>("Connection","keep-alive"));
    //head.insert(std::pair<std::string,std::string>("Accept-Encoding","gzip, deflate, br"));
    //head.insert(std::pair<std::string,std::string>("Accept-Language","zh-CN,zh;q=0.9,en;q=0.8"));
    //head.insert(std::pair<std::string,std::string>("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"));
    //head.insert(std::pair<std::string,std::string>("User-Agent","Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.33 Safari/537.36"));

    std::string url = "https://bitcoinfees.21.co/api/v1/fees/recommended";
    client->request(url,/*head,*/ std::bind(&onResponse, &loop, resp));
    loop.start();

    cout << "resp:" << resp.dump() << endl;
    
    return 0;   
}
