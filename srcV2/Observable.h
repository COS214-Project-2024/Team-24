#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observer.h"
#include "Command.h"

class Observable {
private:
    std::vector<Observer*> observers;  // List of observers

public:
    // Virtual destructor
    virtual ~Observable() = default;

    // Observer management
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    
    // Notification method
    void notifyObservers(Command* cmd);
};

#endif // OBSERVABLE_H 