#include "EventQueue.h"

EventQueue::EventQueue()
{
}

void EventQueue::addEvent(Command *cmd)
{
     events.push(cmd);
}

void EventQueue::processEvents()
{
    while (!events.empty()) {
            Command* cmd = events.front();
            cmd->execute();
            eventhistory.push(cmd);
            events.pop();
        }
}

void EventQueue::undoLastEvent()
{
     while (!events.empty()) {
            Command* cmd = events.front();
            cmd->execute();
            eventhistory.push(cmd);
            events.pop();
        }
}
