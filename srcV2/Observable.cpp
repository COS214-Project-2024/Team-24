#include "Observable.h"
#include <algorithm>

void Observable::addObserver(Observer* obs) {
    if (obs) {
        // Check if observer already exists to avoid duplicates
        auto it = std::find(observers.begin(), observers.end(), obs);
        if (it == observers.end()) {
            observers.push_back(obs);
        }
    }
}

void Observable::removeObserver(Observer* obs) {
    if (obs) {
        auto it = std::find(observers.begin(), observers.end(), obs);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }
}

void Observable::notifyObservers(Command* cmd) {
    // Notify all observers of the change
    for (Observer* observer : observers) {
        if (observer) {
            observer->update(cmd);
        }
    }
} 