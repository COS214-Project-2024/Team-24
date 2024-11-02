#ifndef CRISIS_H
#define CRISIS_H

#include <iostream>
#include <vector>

class Crisis{
    private:
        std::string type;
        int severity, duration;
        std::vector<std::string> affectedAreas;

    public:
        void applyEffects();

        void resolveCrisis();

        double calculateImpact();
};

#endif