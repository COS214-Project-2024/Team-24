#include "MaintenanceVisitor.h"
#include "Residential.cpp"
#include "Industrial.cpp"
#include "Commercial.cpp"
#include "Landmark.cpp"

void MaintenanceVisitor::visitIndustrial(Industrial* building)
{
    std::cout<<"The industrial building is now being maintained."<<std::endl;
    building->maintain();
}

void MaintenanceVisitor::visitResidential(Residential* building)
{
    std::cout<<"The residential building is maintained without disturbing neighbouring residents."<<std::endl;
    building->maintain();
}

void MaintenanceVisitor::visitCommercial(Commercial* building)
{
    std::cout<<"The commercial building is being maintained."<<std::endl;
    building->maintain();
}

void MaintenanceVisitor::visitLandmark(Landmark* building)
{
    std::cout<<"The landmark is being maintained but carefully preserved."<<std::endl;
    building->maintain();
}