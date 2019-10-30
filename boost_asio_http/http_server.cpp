#include "boost_asio_http_header.h"

boost_asio_http::http::server::server()
{
}

void boost_asio_http::http::server::add_route(
    std::string path,
    std::function<void(request&, response&)> handle
)
{
    route_ptr->add(path, handle);
}

void boost_asio_http::http::server::run()
{
    std::shared_ptr<boost::asio::io_service> io_service_ptr = std::make_shared<boost::asio::io_service>();
    listen l(io_service_ptr, route_ptr, "0.0.0.0", server_listen_port);
    io_service_ptr->run();
}
