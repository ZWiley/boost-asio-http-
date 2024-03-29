#include <string>
#include <array>
#include <cstdint>

const std::string   server_name                    = "boost_asio_http";
const std::string   server_version                 = "0.01-alpha";

const std::uint16_t server_listen_port             = 8000;

const std::size_t   http_msg_buffer_length         = 4  * 1024;
const std::size_t   http_msg_first_line_max_length = 8  * 1024;
const std::size_t   http_msg_header_max_length     = 16 * 1024;
const std::size_t   http_msg_body_max_length       = 16 * 1024 * 1024;

namespace boost_asio_http
{
    namespace http
    {
        typedef std::array<unsigned char, http_msg_buffer_length> http_msg_buffer;
    }
}
