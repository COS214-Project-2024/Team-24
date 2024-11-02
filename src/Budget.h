#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <map>

class Budget{
    private:
        double income, expenses, reserves;
        std::map<std::string, double> allocations;

    public:
        bool allocateFunds(std::string department, double amount);

        void collectTaxes();

        std::string generateReport();
};

#endif