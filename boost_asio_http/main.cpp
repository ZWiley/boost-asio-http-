#include "boost_asio_http_core.h"

void hello_page(boost_asio_http::http::request &_request, boost_asio_http::http::response &_response)
{
    _response.msg_body("hello_world\n");
}

void raw_msg(boost_asio_http::http::request &_request, boost_asio_http::http::response &_response)
{
    _response.msg_body(_request.raw_msg());
}

int main()
{
    boost_asio_http::http::server http_server;
    http_server.add_route("/", hello_page);
    http_server.add_route("/raw_msg", raw_msg);
    http_server.run();
}