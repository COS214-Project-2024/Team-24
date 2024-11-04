#ifndef RESOURCEREQUESTHANDLER_H
#define RESOURCEREQUESTHANDLER_H

#include "RequestHandler.h"

class ResourceRequestHandler : public RequestHandler {
public:
    using RequestHandler::RequestHandler;

    void handleRequest(const std::string& request) override;
};

#endif // RESOURCEREQUESTHANDLER_H
