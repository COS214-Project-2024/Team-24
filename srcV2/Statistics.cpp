#include "Statistics.h"
#include <iostream>
#include <numeric>
#include <algorithm>

Statistics::Statistics(size_t maxHistorySize)
    : maxHistory(maxHistorySize) {
    std::cout << "Statistics system initialized with max history size: " 
              << maxHistory << std::endl;
}

void Statistics::addDataPoint(const std::string& metric, double value) {
    // Add to history
    history[metric].push_back(value);
    
    // Update current value
    currentValues[metric] = value;
    
    // Trim history if needed
    if (history[metric].size() > maxHistory) {
        history[metric].pop_front();
    }
    
    std::cout << "Added data point for " << metric << ": " << value << std::endl;
}

void Statistics::clearHistory(const std::string& metric) {
    history[metric].clear();
    currentValues.erase(metric);
    averages.erase(metric);
    minimums.erase(metric);
    maximums.erase(metric);
    growthRates.erase(metric);
    
    std::cout << "Cleared history for metric: " << metric << std::endl;
}

void Statistics::clearAllHistory() {
    history.clear();
    currentValues.clear();
    averages.clear();
    minimums.clear();
    maximums.clear();
    growthRates.clear();
    
    std::cout << "Cleared all statistical history" << std::endl;
}

double Statistics::getCurrentValue(const std::string& metric) const {
    auto it = currentValues.find(metric);
    return (it != currentValues.end()) ? it->second : 0.0;
}

double Statistics::getAverage(const std::string& metric) const {
    auto it = averages.find(metric);
    return (it != averages.end()) ? it->second : 0.0;
}

double Statistics::getMin(const std::string& metric) const {
    auto it = minimums.find(metric);
    return (it != minimums.end()) ? it->second : 0.0;
}

double Statistics::getMax(const std::string& metric) const {
    auto it = maximums.find(metric);
    return (it != maximums.end()) ? it->second : 0.0;
}

double Statistics::getGrowthRate(const std::string& metric) const {
    auto it = growthRates.find(metric);
    return (it != growthRates.end()) ? it->second : 0.0;
}

void Statistics::updateMetrics() {
    calculateAverages();
    calculateMinMax();
    calculateGrowthRates();
    trimHistory();
}

bool Statistics::isMetricImproving(const std::string& metric) const {
    auto it = growthRates.find(metric);
    if (it != growthRates.end()) {
        return it->second > 0.0;
    }
    return false;
}

std::string Statistics::getMetricStatus(const std::string& metric) const {
    auto it = history.find(metric);
    if (it == history.end() || it->second.empty()) {
        return "No data available";
    }

    std::string status = metric + " Status:\n";
    status += "Current: " + std::to_string(getCurrentValue(metric)) + "\n";
    status += "Average: " + std::to_string(getAverage(metric)) + "\n";
    status += "Min: " + std::to_string(getMin(metric)) + "\n";
    status += "Max: " + std::to_string(getMax(metric)) + "\n";
    status += "Growth Rate: " + std::to_string(getGrowthRate(metric)) + "\n";
    status += "Trend: " + std::string(isMetricImproving(metric) ? "Improving" : "Declining");

    return status;
}

void Statistics::calculateAverages() {
    for (const auto& [metric, values] : history) {
        if (!values.empty()) {
            double sum = std::accumulate(values.begin(), values.end(), 0.0);
            averages[metric] = sum / values.size();
        }
    }
}

void Statistics::calculateMinMax() {
    for (const auto& [metric, values] : history) {
        if (!values.empty()) {
            auto [min, max] = std::minmax_element(values.begin(), values.end());
            minimums[metric] = *min;
            maximums[metric] = *max;
        }
    }
}

void Statistics::calculateGrowthRates() {
    for (const auto& [metric, values] : history) {
        if (values.size() >= 2) {
            // Calculate growth rate between last two values
            double oldValue = *(values.end() - 2);
            double newValue = values.back();
            
            if (oldValue != 0) {
                growthRates[metric] = (newValue - oldValue) / oldValue;
            } else {
                growthRates[metric] = newValue > 0 ? 1.0 : 0.0;
            }
        }
    }
}

void Statistics::trimHistory() {
    for (auto& [metric, values] : history) {
        while (values.size() > maxHistory) {
            values.pop_front();
        }
    }
} 