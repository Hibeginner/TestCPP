#include "UDPClient.h"

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <boost/asio.hpp>

using boost::asio::ip::udp;
enum {
    max_length = 1024
};


int main(int argc, char** argv) {
    try {
        boost::asio::io_service ioService;


        boost::asio::ip::udp::endpoint localEndpoint(boost::asio::ip::udp::v4(), 0);
        boost::asio::ip::udp::endpoint remoteEndpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 2300);
        boost::asio::ip::udp::socket udpSocket(ioService, localEndpoint);
        boost::asio::ip::udp::endpoint trueLocalPoint = udpSocket.local_endpoint();
        std::cout << trueLocalPoint.address() << std::endl;
        std::cout << trueLocalPoint.port() << std::endl;

        while (true)
        {
            std::cout << "Enter message: ";

            char request[max_length];

            std::cin.getline(request, max_length);

            size_t request_length = std::strlen(request);

            udpSocket.send_to(boost::asio::buffer(request, request_length), remoteEndpoint);
            trueLocalPoint = udpSocket.local_endpoint();
            std::cout << trueLocalPoint.address() << std::endl;
            std::cout << trueLocalPoint.port() << std::endl;
            char reply[max_length];

            udp::endpoint epserver;

            size_t reply_length = udpSocket.receive_from(boost::asio::buffer(reply, max_length), epserver);
            std::cout << "Reply is: ";
            std::cout.write(reply, reply_length);
            std::cout << "\n";
            trueLocalPoint = udpSocket.local_endpoint();
            std::cout << trueLocalPoint.address() << std::endl;
            std::cout << trueLocalPoint.port() << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception" << e.what() << "\n";
    }
    return 0;
}