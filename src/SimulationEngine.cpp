#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(){
	instance = new SimulationEngine();
}

SimulationEngine* SimulationEngine::getInstance(){
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
	// TODO - implement SimulationEngine::addObserver
	throw "Not yet implemented";
}

void SimulationEngine::removeObserver(Observer* obs) {
	// TODO - implement SimulationEngine::removeObserver
	throw "Not yet implemented";
}

void SimulationEngine::notify(Command* cmd) {
	// TODO - implement SimulationEngine::notify
	throw "Not yet implemented";
}
