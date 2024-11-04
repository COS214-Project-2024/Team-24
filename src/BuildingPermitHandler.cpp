#include "BuildingPermitHandler.h"

void BuildingPermitHandler::handleRequest(const std::string& request) {
    if (request == "BuildingPermit") {
        std::cout << "BuildingPermitHandler: Handling building permit request." << std::endl;
    } else {
        RequestHandler::handleRequest(request);
    }
}
