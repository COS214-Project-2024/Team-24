#include <gtest/gtest.h>
#include "../src/TaxPolicy.h"
#include "../src/ZoningPolicy.h"
#include "../src/EnvironmentalPolicy.h"
#include "../src/Government.h"

class PolicyTests : public ::testing::Test {
protected:
    Government* government;

    void SetUp() override {
        government = new Government("Test City");
    }

    void TearDown() override {
        delete government;
    }
};

// Test Tax Policy Creation and Properties
TEST_F(PolicyTests, TaxPolicyBasics) {
    TaxPolicy taxPolicy("Income Tax", "Basic income tax policy", 
                       1000.0, 0.1, 0.05, "income");
    
    EXPECT_EQ(taxPolicy.getName(), "Income Tax");
    EXPECT_EQ(taxPolicy.getDescription(), "Basic income tax policy");
    EXPECT_EQ(taxPolicy.getCost(), 1000.0);
    EXPECT_EQ(taxPolicy.getImpact(), 0.1);
    EXPECT_EQ(taxPolicy.getTaxRate(), 0.05);
    EXPECT_FALSE(taxPolicy.getIsActive());
}

// Test Tax Policy Implementation
TEST_F(PolicyTests, TaxPolicyImplementation) {
    TaxPolicy taxPolicy("Property Tax", "Property tax policy", 
                       800.0, 0.15, 0.03, "property");
    
    taxPolicy.setActive(true);
    EXPECT_TRUE(taxPolicy.getIsActive());
    
    taxPolicy.setTaxRate(0.04);
    EXPECT_EQ(taxPolicy.getTaxRate(), 0.04);
    
    taxPolicy.implement();
    EXPECT_TRUE(taxPolicy.getIsActive());
}

// Test Zoning Policy Creation and Properties
TEST_F(PolicyTests, ZoningPolicyBasics) {
    ZoningPolicy zoningPolicy("Residential Zone", "Basic residential zoning", 
                             500.0, 0.2, "residential");
    
    EXPECT_EQ(zoningPolicy.getName(), "Residential Zone");
    EXPECT_EQ(zoningPolicy.getDescription(), "Basic residential zoning");
    EXPECT_EQ(zoningPolicy.getCost(), 500.0);
    EXPECT_EQ(zoningPolicy.getImpact(), 0.2);
    EXPECT_FALSE(zoningPolicy.getIsActive());
}

// Test Zoning Policy Implementation
TEST_F(PolicyTests, ZoningPolicyImplementation) {
    ZoningPolicy zoningPolicy("Mixed Use", "Mixed use zoning policy", 
                             600.0, 0.25, "mixed");
    
    zoningPolicy.setDensityLimit(2.0);
    zoningPolicy.setMixedUse(true);
    zoningPolicy.setActive(true);
    zoningPolicy.implement();
    
    EXPECT_TRUE(zoningPolicy.getIsActive());
}

// Test Environmental Policy Creation and Properties
TEST_F(PolicyTests, EnvironmentalPolicyBasics) {
    EnvironmentalPolicy envPolicy("Green Initiative", "Environmental protection", 
                                 2000.0, 0.3, 50.0);
    
    EXPECT_EQ(envPolicy.getName(), "Green Initiative");
    EXPECT_EQ(envPolicy.getDescription(), "Environmental protection");
    EXPECT_EQ(envPolicy.getCost(), 2000.0);
    EXPECT_EQ(envPolicy.getImpact(), 0.3);
    EXPECT_FALSE(envPolicy.getIsActive());
}

// Test Environmental Policy Implementation
TEST_F(PolicyTests, EnvironmentalPolicyImplementation) {
    EnvironmentalPolicy envPolicy("Clean Air", "Air quality policy", 
                                 1500.0, 0.35, 45.0);
    
    envPolicy.setPollutionThreshold(40.0);
    envPolicy.setGreenSpaceRequirement(0.25);
    envPolicy.setActive(true);
    envPolicy.implement();
    
    EXPECT_TRUE(envPolicy.getIsActive());
    EXPECT_TRUE(envPolicy.isImplemented());
}

// Test Policy Effects
TEST_F(PolicyTests, PolicyEffects) {
    TaxPolicy taxPolicy("Sales Tax", "Sales tax policy", 
                       1200.0, 0.2, 0.06, "sales");
    
    double initialEffect = taxPolicy.calculateEffect();
    taxPolicy.setTaxRate(0.08);
    double newEffect = taxPolicy.calculateEffect();
    
    EXPECT_GT(newEffect, initialEffect);
}

// Test Policy Withdrawal
TEST_F(PolicyTests, PolicyWithdrawal) {
    EnvironmentalPolicy envPolicy("Recycling", "Recycling policy", 
                                 1000.0, 0.25, 30.0);
    
    envPolicy.setActive(true);
    envPolicy.implement();
    EXPECT_TRUE(envPolicy.getIsActive());
    
    envPolicy.withdraw();
    EXPECT_FALSE(envPolicy.getIsActive());
} 