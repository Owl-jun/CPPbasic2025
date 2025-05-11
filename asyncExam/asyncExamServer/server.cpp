#include <iostream>
#include <memory>
#include <asio.hpp>

using asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket)
        : socket_(std::move(socket)) {
    }

    void start() {
        read_message();
    }

private:
    void read_message() {
        auto self(shared_from_this());
        asio::async_read_until(socket_, asio::dynamic_buffer(buffer_), "\n",
            [this, self](std::error_code ec, std::size_t length) {
                if (!ec) {
                    std::string message(buffer_.substr(0, length - 1));  // remove '\n'
                    buffer_.erase(0, length);
                    std::cout << "Received: " << message << "\n";

                    write_message(message);
                }
                else {
                    socket_.close();
                    return;
                }
            });
    }

    void write_message(const std::string& message) {
        auto self(shared_from_this());
        asio::async_write(socket_, asio::buffer(message + "\n"),
            [this, self](std::error_code ec, std::size_t) {
                if (!ec) {
                    read_message();  // 다시 수신
                }
                else {
                    socket_.close();
                    return;
                }
            });
    }

    tcp::socket socket_;
    std::string buffer_;
};

class Server {
public:
    Server(asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept(
            [this](std::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket))->start();
                }

                do_accept();
            });
    }

    tcp::acceptor acceptor_;
};

int main() {
    try {
        asio::io_context io_context;

        Server server(io_context, 9000);

        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
