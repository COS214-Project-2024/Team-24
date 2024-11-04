#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <string>
#include <iostream>

class RequestHandler {
protected:
    RequestHandler* successor;

public:
    RequestHandler(RequestHandler* s = nullptr) : successor(s) {}
    virtual ~RequestHandler() = default;

    virtual void handleRequest(const std::string& request) {
        if (successor) {
            successor->handleRequest(request);
        } else {
            std::cout << "Request could not be handled." << std::endl;
        }
    }

    void setSuccessor(RequestHandler* s) { successor = s; }
};

#endif // REQUESTHANDLER_H
