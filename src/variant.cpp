#include <iostream>
#include <string>
#include <variant>
#include <vector>

struct Calculate {
    double d1, d2;
};

struct Colorize {
    int i1, i2;
};

struct Quit {
    std::string text;
};

using Message = std::variant<Calculate, Colorize, Quit>;

void handle(const Calculate& msg)
{
    std::cout << "calculate: " << msg.d1 << ", " << msg.d2 << '\n';
}

void handle(const Colorize& msg)
{
    std::cout << "colorize: " << msg.i1 << ", " << msg.i2 << '\n';
}

void handle(const Quit& msg)
{
    std::cout << "quit: " << msg.text << '\n';
}

void handle_message1(const Message& msg)
{
    if (std::holds_alternative<Calculate>(msg))
        handle(std::get<Calculate>(msg));
    else if (std::holds_alternative<Colorize>(msg))
        handle(std::get<Colorize>(msg));
    else if (std::holds_alternative<Quit>(msg))
        handle(std::get<Quit>(msg));
}

struct Visitor {
    void operator()(const Calculate& msg) { handle(msg); }
    void operator()(const Colorize& msg) { handle(msg); }
    void operator()(const Quit& msg) { handle(msg); }
};

void handle_message2(const Message& msg)
{
    std::visit(Visitor(), msg);
}

void handle_message3(const Message& msg)
{
    auto visitor = [](const auto& m) { handle(m); };
    std::visit(visitor, msg);
}

int main()
{
    std::vector<Message> messages{Calculate{1.0, 2.0}, Colorize{10, 20}, Quit{"done"}};

    for (const auto& msg : messages)
        handle_message1(msg);

    for (const auto& msg : messages)
        handle_message2(msg);

    for (const auto& msg : messages)
        handle_message3(msg);
}
