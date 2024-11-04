#include "CitizenManager.h"

Citizen* CitizenManager::createCitizen(std::string type)
{
    return NULL;
}

void CitizenManager::updateCitizens()
{

}

void CitizenManager::handleCitizenNeeds()
{

}

double CitizenManager::calculateHappiness()
{
    int total;
    int count;

    for (Citizen* citi: citizens)
    {
        count++;
        total += citi->getSatisfaction();
    }

    return total/count;
}