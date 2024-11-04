#ifndef CITYMANAGERIMPL_H
#define CITYMANAGERIMPL_H

#include "CityManager.h"
#include "Building.h"
#include "Citizen.h"
#include "Government.h"
#include "Utility.h"
#include "RoadNetwork.h"
#include <vector>

class CityManagerImpl : public CityManager {
private:
    std::vector<Building*> buildings;
    std::vector<Citizen*> citizens;
    Government* government;
    Utility* utility;
    RoadNetwork* roadNetwork;

public:
    CityManagerImpl() : government(nullptr), utility(nullptr), roadNetwork(nullptr) {}

    void notify(const std::string& event, Colleague* sender) override {
    if (Building* building = dynamic_cast<Building*>(sender)) {
        // Notify all citizens and government of building-related events
        for (auto* citizen : citizens) {
            citizen->receiveNotification("Building Event: " + event);
        }
        if (government) {
            government->receiveNotification("Building Event: " + event);
        }
        if (utility) {
            utility->receiveNotification("Building Event: " + event);
        }
        if (roadNetwork) {
            roadNetwork->receiveNotification("Building Event: " + event);
        }

    } else if (Citizen* citizen = dynamic_cast<Citizen*>(sender)) {
        // Notify the government and all buildings of citizen-related events (e.g., complaints)
        if (government) {
            government->receiveNotification("Citizen Complaint: " + event);
        }
        for (auto* building : buildings) {
            building->receiveNotification("Citizen Complaint: " + event);
        }
        if (utility) {
            utility->receiveNotification("Citizen Complaint: " + event);
        }
        if (roadNetwork) {
            roadNetwork->receiveNotification("Citizen Complaint: " + event);
        }

    } else if (Utility* util = dynamic_cast<Utility*>(sender)) {
        // Notify all citizens, government, and buildings about utility events
        for (auto* citizen : citizens) {
            citizen->receiveNotification("Utility Event: " + event);
        }
        if (government) {
            government->receiveNotification("Utility Event: " + event);
        }
        for (auto* building : buildings) {
            building->receiveNotification("Utility Event: " + event);
        }
        if (roadNetwork) {
            roadNetwork->receiveNotification("Utility Event: " + event);
        }

    } else if (RoadNetwork* roadNet = dynamic_cast<RoadNetwork*>(sender)) {
        // Notify all citizens, government, and buildings about road-related events
        for (auto* citizen : citizens) {
            citizen->receiveNotification("Road Event: " + event);
        }
        if (government) {
            government->receiveNotification("Road Event: " + event);
        }
        for (auto* building : buildings) {
            building->receiveNotification("Road Event: " + event);
        }
        if (utility) {
            utility->receiveNotification("Road Event: " + event);
        }
    }
}


    void registerBuilding(Building* building) {
        buildings.push_back(building);
    }

    void registerCitizen(Citizen* citizen) {
        citizens.push_back(citizen);
    }

    void registerGovernment(Government* gov) {
        government = gov;
    }

    void registerUtility(Utility* util) {
        utility = util;
    }

    void registerRoadNetwork(RoadNetwork* rn) {
        roadNetwork = rn;
    }
};

#endif // CITYMANAGERIMPL_H
