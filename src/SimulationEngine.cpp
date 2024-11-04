#include "SimulationEngine.h"
#include <iostream>
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
	for (Observer* observer : observers){
		if (obs == observer){
			std::cout << "This observer already exists." << std::endl;
			return;
		}
	}

	observers.push_back(obs);
}

void SimulationEngine::removeObserver(Observer* obs) {
	auto it = std::find(observers.begin(), observers.end(), obs);
	if (it != observers.end()){
        observers.erase(it);
    }

	else{
		std::cout << "This observer does not exist." << std::endl;
	}
}

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
