#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "CityManager.h"
#include "TimeManager.h"
#include "Observable.h"
#include <memory>
#include <queue>
#include <functional>

enum class SimulationSpeed {
    PAUSED,
    NORMAL,
    FAST,
    SUPER_FAST
};

enum class SimulationEvent {
    UPDATE,
    START,
    STOP,
    PAUSE,
    RESUME,
    ERROR
};

class SimulationEngine : public Observable {
public:
    // Singleton access
    static SimulationEngine* getInstance();
    
    // Core simulation control
    void start();
    void stop();
    void pause();
    void resume();
    void update();
    
    // Simulation settings
    void setSpeed(SimulationSpeed speed);
    void setUpdateInterval(double interval);
    
    // Status checks
    bool isRunning() const { return simulationIsActive; }
    bool isPaused() const { return simulationIsPaused; }
    SimulationSpeed getSpeed() const { return currentSpeed; }
    
    // Event handling
    void queueEvent(std::function<void()> event);
    void processEvents();
    
    // Resource getters
    CityManager* getCityManager() const { return cityManager.get(); }
    TimeManager* getTimeManager() const { return timeManager.get(); }

private:
    // Private constructor (Singleton)
    SimulationEngine();
    ~SimulationEngine();
    
    // Prevent copying
    SimulationEngine(const SimulationEngine&) = delete;
    SimulationEngine& operator=(const SimulationEngine&) = delete;

    // Simulation state
    bool simulationIsActive{false};
    bool simulationIsPaused{false};
    SimulationSpeed currentSpeed{SimulationSpeed::NORMAL};
    double updateInterval{1.0};
    
    // Core managers
    std::unique_ptr<CityManager> cityManager;
    std::unique_ptr<TimeManager> timeManager;
    
    // Event queue
    std::queue<std::function<void()>> eventQueue;
    
    // Singleton instance
    static SimulationEngine* instance;
    
    // Private utility methods
    void initialize();
    void cleanup();
    void notifyStateChange(SimulationEvent event);
};

#endif // SIMULATIONENGINE_H
