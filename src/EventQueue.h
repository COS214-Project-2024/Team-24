#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include <stack>
#include "Command.h"

/**
 * @class EventQueue
 * @brief Manages a sequence of command events, allowing for processing and undoing of commands.
 *
 * The EventQueue class provides functionality to add command events to a queue, 
 * process them in a First-In-First-Out (FIFO) order, and store processed commands
 * in a history stack for potential undo operations.
 */
class EventQueue {
public:
    /**
     * @brief Constructs an EventQueue object.
     * 
     * Initializes an empty queue and stack for managing command events and history.
     */
    EventQueue();

    /**
     * @brief Adds a command event to the queue.
     * 
     * This method enqueues a new Command object, which can be processed later in 
     * the order it was added.
     *
     * @param cmd Pointer to the Command object to be added to the queue.
     */
    void addEvent(Command* cmd);

    /**
     * @brief Processes all events in the queue.
     * 
     * This method dequeues each Command from the queue, executes it, and stores it
     * in the history stack for potential undo actions.
     */
    void processEvents();

    /**
     * @brief Undoes the last processed event.
     * 
     * This method retrieves the last processed Command from the history stack and 
     * re-executes it in reverse if supported by the Command interface.
     * Note: This method does not directly reverse the command but allows for a reprocessing option.
     */
    void undoLastEvent();

private:
    std::queue<Command*> events; ///< Queue of commands to be processed in FIFO order.
    std::stack<Command*> eventhistory; ///< Stack storing the history of processed commands for undo functionality.
};

#endif // EVENTQUEUE_H
