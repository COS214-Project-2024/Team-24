#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <vector>
#include "Observer.h"
#include "Command.h"

class SimulationEngine {
private:
	std::vector<Observer*> observers;

	static SimulationEngine* instance;
	bool simulationIsActive;

	SimulationEngine();

public:
	static SimulationEngine* getInstance();

	void simulationLoop();

	void stopSimulation();

	void addObserver(Observer* obs);

	void removeObserver(Observer* obs);

	void notify(Command* cmd);
};

#endif
