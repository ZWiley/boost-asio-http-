#include "boost_asio_http_header.h"

boost_asio_http::http::listen::listen(
    std::shared_ptr<boost::asio::io_service> io_service_ptr,
    std::shared_ptr<route>                   route_ptr,
    std::string                              ip,
    std::uint32_t                            port
)
:io_service_ptr(io_service_ptr)
,route_ptr(route_ptr)
,acceptor(*io_service_ptr, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port))
,socket(*io_service_ptr)
{
    do_accept();
}

void boost_asio_http::http::listen::do_accept()
{
    acceptor.async_accept(
        socket,
        [this](boost::system::error_code ec)
        {
            if (!ec)
            {
                std::make_shared<session>(io_service_ptr, route_ptr,std::move(socket))->start();
            }
            do_accept();
        }
    );
}
