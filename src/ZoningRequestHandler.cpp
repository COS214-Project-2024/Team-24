#include "ZoningRequestHandler.h"

void ZoningRequestHandler::handleRequest(const std::string& request) {
    if (request == "ZoningRequest") {
        std::cout << "ZoningRequestHandler: Handling zoning request." << std::endl;
    } else {
        RequestHandler::handleRequest(request);
    }
}
