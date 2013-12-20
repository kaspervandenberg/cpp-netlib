//          Copyright Dean Michael Berris 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <boost/network/protocol/http/client.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

int main(int argc, char * argv[]) {
    using namespace boost::network;
    namespace asio = boost::asio;

    if (argc != 2) { std::cout << "Usage: " << argv[0] << " <url>" << std::endl; return 1; }

    boost::shared_ptr<asio::io_service> io_service = boost::make_shared<asio::io_service>();
    http::client client(http::client::options()
            .io_service(io_service));
    http::client::request request(argv[1]);
    request << header("Connection", "close");
    http::client::response response = client.get(request);
    std::cout << body(response) << std::endl;

    io_service->stop();
    return 0;
}

