#ifndef _boost_asio_http_HTTP_SERVER_H_
#define _boost_asio_http_HTTP_SERVER_H_

namespace boost_asio_http
{
    namespace http
    {
        class server
        {
        public:
            server();
            server& operator=(const server&) = delete;
            void add_route(
                std::string path,
                std::function<void(request&, response&)> handle
            );
            void run();
        private:
            std::shared_ptr<route> route_ptr = std::make_shared<route>();
        };
    }
}

#endif
