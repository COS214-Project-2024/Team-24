#include "SimulationEngine.h"
#include <iostream>
#include <stdexcept>
#include "SimulationCommands.h"

// Initialize static instance
SimulationEngine* SimulationEngine::instance = nullptr;

SimulationEngine* SimulationEngine::getInstance() {
    if (!instance) {
        instance = new SimulationEngine();
    }
    return instance;
}

SimulationEngine::SimulationEngine() {
    try {
        initialize();
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize SimulationEngine: " << e.what() << std::endl;
        cleanup();
        throw;
    }
}

SimulationEngine::~SimulationEngine() {
    cleanup();
    instance = nullptr;
}

void SimulationEngine::initialize() {
    std::cout << "Initializing Simulation Engine..." << std::endl;
    
    // Initialize managers
    cityManager = std::make_unique<CityManager>("New City");
    timeManager = std::make_unique<TimeManager>();
    
    // Set default state
    simulationIsActive = false;
    simulationIsPaused = false;
    currentSpeed = SimulationSpeed::NORMAL;
    updateInterval = 1.0;
    
    std::cout << "Simulation Engine initialized successfully" << std::endl;
}

void SimulationEngine::cleanup() {
    std::cout << "Cleaning up Simulation Engine..." << std::endl;
    
    // Clear event queue
    while (!eventQueue.empty()) {
        eventQueue.pop();
    }
    
    // Cleanup managers (smart pointers will handle deletion)
    cityManager.reset();
    timeManager.reset();
}

void SimulationEngine::start() {
    if (!simulationIsActive) {
        simulationIsActive = true;
        simulationIsPaused = false;
        std::cout << "Simulation started" << std::endl;
        notifyStateChange(SimulationEvent::START);
    }
}

void SimulationEngine::stop() {
    if (simulationIsActive) {
        simulationIsActive = false;
        simulationIsPaused = false;
        std::cout << "Simulation stopped" << std::endl;
        notifyStateChange(SimulationEvent::STOP);
    }
}

void SimulationEngine::pause() {
    if (simulationIsActive && !simulationIsPaused) {
        simulationIsPaused = true;
        std::cout << "Simulation paused" << std::endl;
        notifyStateChange(SimulationEvent::PAUSE);
    }
}

void SimulationEngine::resume() {
    if (simulationIsActive && simulationIsPaused) {
        simulationIsPaused = false;
        std::cout << "Simulation resumed" << std::endl;
        notifyStateChange(SimulationEvent::RESUME);
    }
}

void SimulationEngine::update() {
    if (!simulationIsActive || simulationIsPaused) {
        return;
    }

    try {
        // Update time
        timeManager->update();
        
        // Update city
        cityManager->update();
        
        // Process queued events
        processEvents();
        
        // Notify observers
        notifyStateChange(SimulationEvent::UPDATE);
        
    } catch (const std::exception& e) {
        std::cerr << "Error during simulation update: " << e.what() << std::endl;
        notifyStateChange(SimulationEvent::ERROR);
    }
}

void SimulationEngine::setSpeed(SimulationSpeed speed) {
    currentSpeed = speed;
    switch (speed) {
        case SimulationSpeed::PAUSED:
            updateInterval = 0.0;
            pause();
            break;
        case SimulationSpeed::NORMAL:
            updateInterval = 1.0;
            break;
        case SimulationSpeed::FAST:
            updateInterval = 0.5;
            break;
        case SimulationSpeed::SUPER_FAST:
            updateInterval = 0.1;
            break;
    }
    std::cout << "Simulation speed changed to: " << static_cast<int>(speed) << std::endl;
}

void SimulationEngine::queueEvent(std::function<void()> event) {
    eventQueue.push(event);
}

void SimulationEngine::processEvents() {
    while (!eventQueue.empty()) {
        try {
            auto event = eventQueue.front();
            eventQueue.pop();
            event();
        } catch (const std::exception& e) {
            std::cerr << "Error processing event: " << e.what() << std::endl;
        }
    }
}

void SimulationEngine::notifyStateChange(SimulationEvent event) {
    std::unique_ptr<Command> cmd;
    
    switch(event) {
        case SimulationEvent::START:
            cmd = std::make_unique<StartSimulationCommand>(this);
            break;
            
        case SimulationEvent::STOP:
            cmd = std::make_unique<StopSimulationCommand>(this);
            break;
            
        case SimulationEvent::PAUSE:
            cmd = std::make_unique<PauseSimulationCommand>(this);
            break;
            
        case SimulationEvent::UPDATE:
            cmd = std::make_unique<UpdateSimulationCommand>(this);
            break;
            
        case SimulationEvent::ERROR:
            std::cerr << "Simulation error occurred" << std::endl;
            return;
            
        default:
            std::cerr << "Unknown simulation event" << std::endl;
            return;
    }
    
    if (cmd) {
        notifyObservers(cmd.get());
    }
}

