#include "SimulationFacade.h"
#include <iostream>

SimulationFacade::SimulationFacade() {
    std::cout << "Initializing Simulation Facade" << std::endl;
    engine = SimulationEngine::getInstance();
    cityManager = std::make_unique<CityManager>("New City");
}

SimulationFacade::~SimulationFacade() {
    clearEventQueue();
    std::cout << "Simulation Facade destroyed" << std::endl;
}

void SimulationFacade::initializeSimulation() {
    std::cout << "Initializing simulation..." << std::endl;
    loadInitialConfiguration();
    if (engine) {
        engine->setSpeed(SimulationSpeed::NORMAL);
    }
}

void SimulationFacade::runSimulation() {
    std::cout << "Starting simulation..." << std::endl;
    if (engine) {
        engine->start();
    }
}

void SimulationFacade::pauseSimulation() {
    std::cout << "Pausing simulation..." << std::endl;
    if (engine) {
        engine->pause();
    }
}

void SimulationFacade::processEvents() {
    std::cout << "Processing events..." << std::endl;
    
    // Process all events in queue
    for (auto& command : eventQueue) {
        if (command) {
            command->execute();
        }
    }
    
    clearEventQueue();
}

void SimulationFacade::loadInitialConfiguration() {
    std::cout << "Loading initial configuration..." << std::endl;
    // Load initial city setup
    // Set up initial resources
    // Initialize starting population
}

void SimulationFacade::clearEventQueue() {
    std::cout << "Clearing event queue..." << std::endl;
    eventQueue.clear();
} 