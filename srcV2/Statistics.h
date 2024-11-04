#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <map>
#include <vector>
#include <deque>

class Statistics {
public:
    // Constructor
    Statistics(size_t maxHistorySize = 100);

    // Data management
    void addDataPoint(const std::string& metric, double value);
    void clearHistory(const std::string& metric);
    void clearAllHistory();

    // Getters
    double getCurrentValue(const std::string& metric) const;
    double getAverage(const std::string& metric) const;
    double getMin(const std::string& metric) const;
    double getMax(const std::string& metric) const;
    double getGrowthRate(const std::string& metric) const;

    // Analysis
    void updateMetrics();
    bool isMetricImproving(const std::string& metric) const;
    std::string getMetricStatus(const std::string& metric) const;

private:
    // Data storage
    std::map<std::string, std::deque<double>> history;
    std::map<std::string, double> currentValues;
    std::map<std::string, double> averages;
    std::map<std::string, double> minimums;
    std::map<std::string, double> maximums;
    std::map<std::string, double> growthRates;

    size_t maxHistory;

    // Private utility methods
    void calculateAverages();
    void calculateMinMax();
    void calculateGrowthRates();
    void trimHistory();
};

#endif // STATISTICS_H
