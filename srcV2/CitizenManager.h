#ifndef CITIZENMANAGER_H
#define CITIZENMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Citizen.h"

class CitizenManager {
private:
    std::vector<std::unique_ptr<Citizen>> citizens;

public:
    CitizenManager() = default;
    ~CitizenManager() = default;

    CitizenManager(const CitizenManager&) = delete;
    CitizenManager& operator=(const CitizenManager&) = delete;

    std::unique_ptr<Citizen> createCitizen(const std::string& name);
    void updateCitizens();
    void handleCitizenNeeds();
    double calculateHappiness() const;

    size_t getCitizenCount() const { return citizens.size(); }
    void removeCitizen(long id);
    const std::vector<std::unique_ptr<Citizen>>& getCitizens() const { return citizens; }
};

#endif
