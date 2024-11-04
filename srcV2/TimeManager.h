#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <chrono>

class TimeManager {
public:
    static TimeManager& getInstance() {
        static TimeManager instance;
        return instance;
    }

    // Delete copy constructor and assignment operator
    TimeManager(const TimeManager&) = delete;
    TimeManager& operator=(const TimeManager&) = delete;

    void update();
    void pause();
    void resume();
    void setSpeed(double speed);
    void setTimeScale(double scale);
    
    bool isPaused() const { return paused; }
    double getSpeed() const { return simulationSpeed; }
    int getGameTime() const { return gameTime; }
    bool isEndOfMonth() const;
    bool isEndOfYear() const;
    TimeManager() = default;

private:
    
    void advanceTime();
    
    bool paused{false};
    double simulationSpeed{1.0};
    int gameTime{0};
    int day{1};
    int month{1};
    int year{2024};
    std::chrono::steady_clock::time_point lastUpdate{std::chrono::steady_clock::now()};
};

#endif
