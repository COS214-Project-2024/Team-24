#ifndef BUILDINGPERMITHANDLER_H
#define BUILDINGPERMITHANDLER_H

#include "RequestHandler.h"

class BuildingPermitHandler : public RequestHandler {
public:
    using RequestHandler::RequestHandler;

    void handleRequest(const std::string& request) override;
};

#endif // BUILDINGPERMITHANDLER_H
