#include "EventQueue.h"

/**
 * @brief Default constructor for EventQueue.
 *
 * Initializes an empty event queue and event history stack.
 */
EventQueue::EventQueue() {
    // Constructor initializes an empty EventQueue.
}

/**
 * @brief Adds a command event to the queue.
 *
 * This method enqueues a new Command object, which will be processed
 * in the order it was added when `processEvents()` is called.
 *
 * @param cmd Pointer to the Command object to add to the queue.
 */
void EventQueue::addEvent(Command* cmd) {
    events.push(cmd);  // Add the command to the event queue.
}

/**
 * @brief Processes all events in the queue.
 *
 * This method dequeues each Command from `events`, executes it,
 * and stores it in `eventhistory` for potential undo actions.
 * It continues processing until the queue is empty.
 */
void EventQueue::processEvents() {
    while (!events.empty()) {
        Command* cmd = events.front();  // Get the command at the front of the queue.
        cmd->execute();                 // Execute the command.
        eventhistory.push(cmd);         // Store the command in history for undo capability.
        events.pop();                   // Remove the command from the queue.
    }
}

/**
 * @brief Undoes the last processed event.
 *
 * This method retrieves the last executed Command from `eventhistory`,
 * calls its `undo()` method, and removes it from `eventhistory`.
 * If there are no commands to undo, it outputs a message.
 *
 * Assumes that the Command interface provides an `undo()` method
 * that reverses the effect of `execute()`.
 */
void EventQueue::undoLastEvent() {
    if (!eventhistory.empty()) {
        Command* lastCmd = eventhistory.top();  // Get the last executed command.
        lastCmd->undo();                        // Call the undo method on the command.
        eventhistory.pop();                     // Remove it from the history stack.
    } else {
        std::cout << "No events to undo." << std::endl;  // Inform the user if there's nothing to undo.
    }
}
