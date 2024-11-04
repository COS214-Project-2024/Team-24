#ifndef SIMULATION_COMMANDS_H
#define SIMULATION_COMMANDS_H

#include "Command.h"
#include "SimulationEngine.h"

// Start Simulation Command
class StartSimulationCommand : public Command {
public:
    explicit StartSimulationCommand(SimulationEngine* engine)
        : Command("Start Simulation")
        , engine(engine) {}

    void execute() override {
        if (engine) engine->start();
    }

    void undo() override {
        if (engine) engine->stop();
    }

private:
    SimulationEngine* engine;
};

// Stop Simulation Command
class StopSimulationCommand : public Command {
public:
    explicit StopSimulationCommand(SimulationEngine* engine)
        : Command("Stop Simulation")
        , engine(engine) {}

    void execute() override {
        if (engine) engine->stop();
    }

    void undo() override {
        if (engine) engine->start();
    }

private:
    SimulationEngine* engine;
};

// Pause Simulation Command
class PauseSimulationCommand : public Command {
public:
    explicit PauseSimulationCommand(SimulationEngine* engine)
        : Command("Pause Simulation")
        , engine(engine) {}

    void execute() override {
        if (engine) engine->pause();
    }

    void undo() override {
        if (engine) engine->resume();
    }

private:
    SimulationEngine* engine;
};

// Update Simulation Command
class UpdateSimulationCommand : public Command {
public:
    explicit UpdateSimulationCommand(SimulationEngine* engine)
        : Command("Update Simulation")
        , engine(engine) {}

    void execute() override {
        if (engine) engine->update();
    }

    void undo() override {
        // Cannot undo an update
    }

private:
    SimulationEngine* engine;
};

#endif // SIMULATION_COMMANDS_H 