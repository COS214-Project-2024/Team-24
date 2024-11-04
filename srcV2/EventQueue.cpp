#include "EventQueue.h"

EventQueue::EventQueue() = default;

void EventQueue::addEvent(std::unique_ptr<Command> cmd) {
    events.push(std::move(cmd));
}

void EventQueue::processEvents() {
    while (!events.empty()) {
        auto cmd = std::move(events.front());
        events.pop();
        cmd->execute();
        eventHistory.push_back(std::move(cmd));
    }
}

void EventQueue::undoLastEvent() {
    if (!eventHistory.empty()) {
        auto cmd = std::move(eventHistory.back());
        eventHistory.pop_back();
        cmd->undo();
    }
} 