#include "BuildingVisitor.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include <iostream>


BuildingVisitor::~BuildingVisitor() {
    std::cout << "Building visitor destroyed" << std::endl;
} 