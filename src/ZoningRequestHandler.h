#ifndef ZONINGREQUESTHANDLER_H
#define ZONINGREQUESTHANDLER_H

#include "RequestHandler.h"

class ZoningRequestHandler : public RequestHandler {
public:
    using RequestHandler::RequestHandler;

    void handleRequest(const std::string& request) override;
};

#endif // ZONINGREQUESTHANDLER_H
