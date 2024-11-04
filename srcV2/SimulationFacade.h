#ifndef SIMULATIONFACADE_H
#define SIMULATIONFACADE_H

#include <vector>
#include <memory>
#include "SimulationEngine.h"
#include "CityManager.h"
#include "Command.h"

class SimulationFacade {
public:
    // Constructor and Destructor
    SimulationFacade();
    ~SimulationFacade();

    // Public Interface Methods
    void initializeSimulation();   // Initializes simulation components
    void runSimulation();          // Starts the main simulation loop
    void pauseSimulation();        // Pauses the simulation loop
    void processEvents();          // Processes events in the queue

private:
    // Member Variables
    SimulationEngine* engine;                      // Singleton, don't use unique_ptr
    std::unique_ptr<CityManager> cityManager;      // Owns CityManager
    std::vector<std::unique_ptr<Command>> eventQueue;  // Owns Commands

    // Private Helper Methods
    void loadInitialConfiguration();
    void clearEventQueue();
};

#endif // SIMULATIONFACADE_H
