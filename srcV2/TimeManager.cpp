#include "TimeManager.h"
#include <iostream>

void TimeManager::update() {
    if (!paused) {
        advanceTime();
    }
}

void TimeManager::setTimeScale(double scale) {
    if (scale > 0.0) {
        simulationSpeed = scale;
        std::cout << "Time scale set to: " << scale << "x" << std::endl;
    }
}

void TimeManager::pause() {
    paused = true;
    std::cout << "Time paused" << std::endl;
}

void TimeManager::resume() {
    paused = false;
    lastUpdate = std::chrono::steady_clock::now();
    std::cout << "Time resumed" << std::endl;
}

void TimeManager::setSpeed(double speed) {
    if (speed > 0.0) {
        simulationSpeed = speed;
        std::cout << "Simulation speed set to: " << speed << "x" << std::endl;
    }
}

void TimeManager::advanceTime() {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - lastUpdate).count();
    
    // Convert real time to game time based on simulation speed
    int timeIncrement = static_cast<int>(elapsed * simulationSpeed / 1000.0);
    
    if (timeIncrement > 0) {
        gameTime += timeIncrement;
        day += timeIncrement;
        
        // Update calendar
        while (day > 30) {  // Simplified 30-day months
            day -= 30;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        
        lastUpdate = currentTime;
    }
}

bool TimeManager::isEndOfMonth() const {
    return day == 30;  // Simplified 30-day months
}

bool TimeManager::isEndOfYear() const {
    return month == 12 && day == 30;
}