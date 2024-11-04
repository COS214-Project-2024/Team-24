#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include <vector>
#include <memory>
#include "Command.h"

class EventQueue {
public:
    // Constructor and destructor
    EventQueue();
    ~EventQueue() = default;

    // Prevent copying
    EventQueue(const EventQueue&) = delete;
    EventQueue& operator=(const EventQueue&) = delete;

    // Event management
    void addEvent(std::unique_ptr<Command> cmd);
    void processEvents();
    void undoLastEvent();
    
    // Queue information
    bool isEmpty() const { return events.empty(); }
    size_t getQueueSize() const { return events.size(); }
    size_t getHistorySize() const { return eventHistory.size(); }

private:
    // Queue of commands to be processed (using smart pointers)
    std::queue<std::unique_ptr<Command>> events;

    // History of executed commands for undo functionality
    std::vector<std::unique_ptr<Command>> eventHistory;
};

#endif // EVENTQUEUE_H
