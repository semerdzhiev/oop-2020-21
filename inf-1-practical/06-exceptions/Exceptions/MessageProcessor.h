#pragma once

#include <stdexcept>
#include <cstring>
#include <iostream>

class MessageProcessor
{
public:
    MessageProcessor(const char* msg) : message(msg) {}
    static const char* processMessage(const char* messageToProcess)
    {
        if (messageToProcess == nullptr)
        {
            throw std::invalid_argument("Message cannot be nullptr");
        }

        if (strstr(messageToProcess, "error"))
        {
            throw std::runtime_error("Message contains error");
        }

        return messageToProcess;
    }

    void printMessage() const
    {
        try {
            std::cout << processMessage(message) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument " << e.what() << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Runtime error " << e.what() << std::endl;
            throw "lo6o";
        }
    }
private:
    const char* message;
};
