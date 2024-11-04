#include "BuildingState.h"
#include "Building.h"
#include <iostream>

BuildingState::~BuildingState() {
    std::cout << "Building state destroyed" << std::endl;
}

