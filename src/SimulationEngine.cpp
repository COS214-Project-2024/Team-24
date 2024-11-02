#include "SimulationEngine.h"
#include <iostream>

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
	// TODO - implement SimulationEngine::notify
	throw "Not yet implemented";
}
