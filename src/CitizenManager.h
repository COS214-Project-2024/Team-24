#ifndef CITIZENMANAGER_H
#define CITIZENMANAGER_H

#include "Citizen.h"
#include <map>
#include <vector>

class CitizenManager {
private:
    std::map<std::string, Citizen*> citizenPrototypes;
    std::vector<Citizen*> citizens;

public:
    Citizen* createCitizen(std::string type);
    void updateCitizens();
    void handleCitizenNeeds();
    double calculateHappiness();
};

#endif