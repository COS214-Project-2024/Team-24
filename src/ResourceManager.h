#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>

class ResourceManager{
    private:
        double power, water, waste, money;

    public:
        void consumeResources();

        void addResources(std::string type, double amount);

        bool checkResourceAvailablility();
};

#endif