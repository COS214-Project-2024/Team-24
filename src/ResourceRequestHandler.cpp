#include "ResourceRequestHandler.h"

void ResourceRequestHandler::handleRequest(const std::string& request) {
    if (request == "ResourceRequest") {
        std::cout << "ResourceRequestHandler: Handling resource request." << std::endl;
    } else {
        RequestHandler::handleRequest(request);
    }
}
