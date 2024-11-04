#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include <vector>
#include <memory>
#include "Command.h"

/**
 * @class EventQueue
 * @brief Manages a queue of commands with undo functionality.
 *
 * The EventQueue class stores commands to be executed in sequence and
 * supports undo operations for the last executed command.
 */
class EventQueue {
public:
    /// Constructor to initialize the event queue.
    EventQueue();

    /// Destructor.
    ~EventQueue() = default;

    /// Prevents copying of EventQueue.
    EventQueue(const EventQueue&) = delete;
    EventQueue& operator=(const EventQueue&) = delete;

    /**
     * @brief Adds a new event command to the queue.
     * @param cmd The command to be added.
     */
    void addEvent(std::unique_ptr<Command> cmd);

    /// Processes all commands in the event queue.
    void processEvents();

    /// Undoes the last executed event in the history.
    void undoLastEvent();

    /// Checks if the event queue is empty.
    bool isEmpty() const { return events.empty(); }

    /// Returns the size of the event queue.
    size_t getQueueSize() const { return events.size(); }

    /// Returns the size of the event history for undo purposes.
    size_t getHistorySize() const { return eventHistory.size(); }

private:
    std::queue<std::unique_ptr<Command>> events; ///< Queue of commands to be processed.
    std::vector<std::unique_ptr<Command>> eventHistory; ///< History of executed commands.
};

#endif // EVENTQUEUE_H
