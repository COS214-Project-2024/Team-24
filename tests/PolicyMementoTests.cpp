#include <gtest/gtest.h>
#include "../src/PolicyMemento.h"
#include "../src/TaxPolicy.h"
#include "../src/ZoningPolicy.h"
#include "../src/EnvironmentalPolicy.h"
#include <regex>

class PolicyMementoTests : public ::testing::Test {
protected:
    TaxPolicy* taxPolicy;
    ZoningPolicy* zoningPolicy;
    EnvironmentalPolicy* envPolicy;
    PolicyMemento* memento;

    void SetUp() override {
        // Create test policies
        taxPolicy = new TaxPolicy("Test Tax", "Tax Description", 1000.0, 0.1, 0.05, "income");
        zoningPolicy = new ZoningPolicy("Test Zone", "Zone Description", 500.0, 0.2, "residential");
        envPolicy = new EnvironmentalPolicy("Test Env", "Env Description", 2000.0, 0.3, 50.0);
        
        memento = new PolicyMemento(taxPolicy, zoningPolicy, envPolicy);
    }

    void TearDown() override {
        delete memento;
        delete taxPolicy;
        delete zoningPolicy;
        delete envPolicy;
    }
};

// Test Memento Creation
TEST_F(PolicyMementoTests, MementoCreation) {
    EXPECT_NE(memento->getTaxPolicy(), nullptr);
    EXPECT_NE(memento->getZoningPolicy(), nullptr);
    EXPECT_NE(memento->getEnvironmentalPolicy(), nullptr);
}

// Test Timestamp Format
TEST_F(PolicyMementoTests, TimestampFormat) {
    std::string timestamp = memento->getTimestamp();
    // Regex for "YYYY-MM-DD HH:MM:SS" format
    std::regex timestampRegex("\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}");
    EXPECT_TRUE(std::regex_match(timestamp, timestampRegex));
}

// Test Null Policy Handling
TEST_F(PolicyMementoTests, NullPolicyHandling) {
    PolicyMemento nullMemento(nullptr, nullptr, nullptr);
    EXPECT_EQ(nullMemento.getTaxPolicy(), nullptr);
    EXPECT_EQ(nullMemento.getZoningPolicy(), nullptr);
    EXPECT_EQ(nullMemento.getEnvironmentalPolicy(), nullptr);
}

// Test Policy Implementation
TEST_F(PolicyMementoTests, PolicyImplementation) {
    // Test tax policy implementation
    memento->implement("tax");
    EXPECT_TRUE(memento->getTaxPolicy()->getIsActive());
    
    // Test zoning policy implementation
    memento->implement("zoning");
    EXPECT_TRUE(memento->getZoningPolicy()->getIsActive());
    
    // Test environmental policy implementation
    memento->implement("environmental");
    EXPECT_TRUE(memento->getEnvironmentalPolicy()->getIsActive());
}

// Test Invalid Policy Implementation
TEST_F(PolicyMementoTests, InvalidPolicyImplementation) {
    // Should not crash with invalid policy type
    memento->implement("invalid");
    
    // Original policies should remain unchanged
    EXPECT_FALSE(memento->getTaxPolicy()->getIsActive());
    EXPECT_FALSE(memento->getZoningPolicy()->getIsActive());
    EXPECT_FALSE(memento->getEnvironmentalPolicy()->getIsActive());
}

// Test Partial Memento Creation
TEST_F(PolicyMementoTests, PartialMementoCreation) {
    PolicyMemento partialMemento(taxPolicy, nullptr, envPolicy);
    EXPECT_NE(partialMemento.getTaxPolicy(), nullptr);
    EXPECT_EQ(partialMemento.getZoningPolicy(), nullptr);
    EXPECT_NE(partialMemento.getEnvironmentalPolicy(), nullptr);
} 