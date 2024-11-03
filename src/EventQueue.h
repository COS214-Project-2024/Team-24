#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include <stack>
#include "Command.h"

class EventQueue {
public:
    // Constructor
    EventQueue();

    // Adds an event to the queue
    void addEvent(Command* cmd);

    // Processes all events in the queue
    void processEvents();

    // Undoes the last event
    void undoLastEvent();

private:
    // Queue of commands to be processed
    std::queue<Command*> events;
    std::stack<Command*> eventhistory;
};

#endif // EVENTQUEUE_H
