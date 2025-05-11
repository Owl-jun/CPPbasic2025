#include <iostream>
#include <asio.hpp>

using asio::ip::tcp;

class Client : public std::enable_shared_from_this<Client> {
public:
    Client(asio::io_context& io_context,
        const std::string& host, const std::string& port)
        : resolver_(io_context),
        socket_(io_context),
        host_(host),
        port_(port)
    {
    }

    void start() {
        do_resolve(host_, port_);
    }

private:
    void do_resolve(const std::string& host, const std::string& port) {
        auto self(shared_from_this());
        resolver_.async_resolve(host, port,
            [this, self](std::error_code ec, tcp::resolver::results_type endpoints) {
                if (!ec) {
                    do_connect(endpoints);
                }
                else {
                    std::cout << "Resolve failed: " << ec.message() << std::endl;
                    return;
                }
            });
    }

    void do_connect(const tcp::resolver::results_type& endpoints) {
        auto self(shared_from_this());
        asio::async_connect(socket_, endpoints,
            [this, self](std::error_code ec, const tcp::endpoint&) {
                if (!ec) {
                    std::cout << "Connected to server!\n";

                    do_write("Hello Server!\n");
                    do_read();
                }
                else {
                    std::cout << "Connect failed: " << ec.message() << std::endl;
                    return;
                }
            });
    }

    void do_write(const std::string& msg) {
        auto self(shared_from_this());
        asio::async_write(socket_, asio::buffer(msg),
            [this, self](std::error_code ec, std::size_t) {
                if (!ec) {
                    std::cout << "Sent message to server.\n";
                }
                else {
                    socket_.close();
                    return;
                }
            });
    }

    void do_read() {
        auto self(shared_from_this());
        asio::async_read_until(socket_, asio::dynamic_buffer(buffer_), "\n",
            [this, self](std::error_code ec, std::size_t length) {
                if (!ec) {
                    std::string message(buffer_.substr(0, length - 1));
                    buffer_.erase(0, length);

                    std::cout << "Received from server: " << message << std::endl;

                    do_read();
                }
                else {
                    socket_.close();
                    return;
                }
            });
    }

    tcp::resolver resolver_;
    tcp::socket socket_;
    std::string buffer_;
    std::string host_;
    std::string port_;
};

std::shared_ptr<Client> g_client;

int main() {
    asio::io_context io_context;

    g_client = std::make_shared<Client>(io_context, "127.0.0.1", "9000");
    g_client->start();  // <-- 여기서 시작해야 안전!

    io_context.run();
}

