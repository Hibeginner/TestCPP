#include "UDPServer.h"

#include <iostream>
#include "boost/asio.hpp"
#include "boost/system/error_code.hpp"


int main() {
    try {
        std::cout << "udp server start ......" << std::endl;
        boost::asio::io_service ioService;

        boost::asio::ip::udp::endpoint localEndpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 2300);
        boost::asio::ip::udp::socket udpSock(ioService, localEndpoint);

        while (true) {
            char receiveBuff[1024];
            boost::asio::ip::udp::endpoint remoteEndpoint;
            boost::system::error_code tempErrorCode;

            size_t receiveLenght = 0;
            receiveLenght = udpSock.receive_from(boost::asio::buffer(receiveBuff), remoteEndpoint, 0, tempErrorCode);
            std::cout << "Receive is: ";
            std::cout.write(receiveBuff, receiveLenght);
            std::cout << "\n";

            if (tempErrorCode && tempErrorCode != boost::asio::error::message_size) {
                throw boost::system::system_error(tempErrorCode);
            }

            std::cout << "send to " << remoteEndpoint.address() << ":" << remoteEndpoint.port() << std::endl;
            udpSock.send_to(boost::asio::buffer("hello asio udp"), remoteEndpoint);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;

}

