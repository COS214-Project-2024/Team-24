#include "SimulationEngine.h"
#include <stdexcept> 
#include <algorithm>

SimulationEngine::SimulationEngine() {
	instance = new SimulationEngine();
}

SimulationEngine* SimulationEngine::getInstance() {
	return instance;
}

void SimulationEngine::simulationLoop() {
	// TODO - implement SimulationEngine::simulationLoop
	throw "Not yet implemented";
}

void SimulationEngine::stopSimulation() {
	simulationIsActive = false;
}

void SimulationEngine::addObserver(Observer* obs) {
    observers.push_back(obs);
}

void SimulationEngine::removeObserver(Observer* obs) {
	observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
};

void SimulationEngine::notify(Command* cmd) {
    if (cmd == NULL) {
        throw std::invalid_argument("Command cannot be NULL");
    }

    for (size_t i = 0; i < observers.size(); ++i) {
        Observer* obs = observers[i];
        if (obs != NULL) {
            obs->update(cmd);
        }
    }
}
