#ifndef _boost_asio_http_HTTP_ROUTE_H_
#define _boost_asio_http_HTTP_ROUTE_H_

namespace boost_asio_http
{
    namespace http
    {
        /*
        struct binary_tree_route_node
        {
            std::shared_ptr<binary_tree_route_node> left_child;
            std::shared_ptr<binary_tree_route_node> right_child;
            std::string path_item;
            std::function<std::string(boost_asio_http::http::request&, boost_asio_http::http::response&)> handle;
        };
        */

        class route
        {
        public:
            void add
            (
                std::string path,
                std::function<void(request&, response&)> handle
            );
            void run_handle(request &_request, response &_response);
        private:
            std::map<std::string,std::function<void(request&, response&)>> route_table;
        };
    }
}

#endif