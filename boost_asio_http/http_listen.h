#include <stdint.h>

namespace boost_asio_http
{
    namespace http
    {
        class listen : public std::enable_shared_from_this<listen>
        {
        public:
            listen(
                std::shared_ptr<boost::asio::io_service> io_service_ptr,
                std::shared_ptr<route>                   route_ptr,
                std::string                              ip,
                std::uint32_t                            port
            );
            void do_accept();
        private:
            std::shared_ptr<boost::asio::io_service> io_service_ptr;
            std::shared_ptr<route>                   route_ptr;
            boost::asio::ip::tcp::acceptor           acceptor;
            boost::asio::ip::tcp::socket             socket;

            std::string                              ip;
            std::uint32_t                            port;
        };
    }
}