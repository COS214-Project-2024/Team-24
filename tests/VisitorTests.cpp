#include <gtest/gtest.h>
#include "../src/InspectionVisitor.h"
#include "../src/MaintenanceVisitor.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"
#include "../src/Industrial.h"
#include "../src/Landmark.h"
#include "../src/Point.h"

class VisitorTests : public ::testing::Test {
protected:
    InspectionVisitor* inspector;
    MaintenanceVisitor* maintainer;
    Residential* residential;
    Commercial* commercial;
    Industrial* industrial;
    Landmark* landmark;

    void SetUp() override {
        inspector = new InspectionVisitor();
        maintainer = new MaintenanceVisitor();
        
        // Create buildings at different points
        residential = new Residential("Test House", Point(0,0));
        commercial = new Commercial("Test Shop", Point(1,1));
        industrial = new Industrial("Test Factory", Point(2,2));
        landmark = new Landmark("Test Monument", Point(3,3));
    }

    void TearDown() override {
        delete inspector;
        delete maintainer;
        delete residential;
        delete commercial;
        delete industrial;
        delete landmark;
    }
};

// Test Inspection Visitor
TEST_F(VisitorTests, InspectionVisitorResidential) {
    testing::internal::CaptureStdout();  // Start capturing stdout
    inspector->visitResidential(residential);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Inspecting Residential Building") != std::string::npos);
    EXPECT_TRUE(output.find("Occupancy Rate") != std::string::npos);
}

TEST_F(VisitorTests, InspectionVisitorCommercial) {
    testing::internal::CaptureStdout();
    inspector->visitCommercial(commercial);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Inspecting Commercial Building") != std::string::npos);
    EXPECT_TRUE(output.find("Revenue") != std::string::npos);
}

TEST_F(VisitorTests, InspectionVisitorIndustrial) {
    testing::internal::CaptureStdout();
    inspector->visitIndustrial(industrial);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Inspecting Industrial Building") != std::string::npos);
    EXPECT_TRUE(output.find("Production Rate") != std::string::npos);
}

TEST_F(VisitorTests, InspectionVisitorLandmark) {
    testing::internal::CaptureStdout();
    inspector->visitLandmark(landmark);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Inspecting Landmark Building") != std::string::npos);
    EXPECT_TRUE(output.find("Condition") != std::string::npos);
}

// Test Maintenance Visitor
TEST_F(VisitorTests, MaintenanceVisitorResidential) {
    testing::internal::CaptureStdout();  // Capture maintenance report
    maintainer->visitResidential(residential);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Residential Building Maintenance Report") != std::string::npos);
    EXPECT_NEAR(residential->getCondition(), 1.0, 0.1);
}

TEST_F(VisitorTests, MaintenanceVisitorCommercial) {
    testing::internal::CaptureStdout();
    maintainer->visitCommercial(commercial);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Commercial Building Maintenance Report") != std::string::npos);
    EXPECT_NEAR(commercial->getCondition(), 1.0, 0.1);
}

TEST_F(VisitorTests, MaintenanceVisitorIndustrial) {
    testing::internal::CaptureStdout();
    maintainer->visitIndustrial(industrial);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Industrial Building Maintenance Report") != std::string::npos);
    EXPECT_NEAR(industrial->getCondition(), 1.0, 0.1);
}

TEST_F(VisitorTests, MaintenanceVisitorLandmark) {
    testing::internal::CaptureStdout();
    maintainer->visitLandmark(landmark);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Landmark Building Maintenance Report") != std::string::npos);
    EXPECT_NEAR(landmark->getCondition(), 1.0, 0.1);
}

// Test Multiple Maintenance Cycles
TEST_F(VisitorTests, MultipleMaintenance) {
    // Perform multiple maintenance cycles
    for(int i = 0; i < 3; i++) {
        maintainer->visitResidential(residential);
        maintainer->visitCommercial(commercial);
        maintainer->visitIndustrial(industrial);
        maintainer->visitLandmark(landmark);
    }
    
    // All buildings should still be in good condition
    EXPECT_NEAR(residential->getCondition(), 1.0, 0.1);
    EXPECT_NEAR(commercial->getCondition(), 1.0, 0.1);
    EXPECT_NEAR(industrial->getCondition(), 1.0, 0.1);
    EXPECT_NEAR(landmark->getCondition(), 1.0, 0.1);
}

// Test Null Safety
TEST_F(VisitorTests, NullSafety) {
    // These should not crash
    inspector->visitResidential(nullptr);
    inspector->visitCommercial(nullptr);
    inspector->visitIndustrial(nullptr);
    inspector->visitLandmark(nullptr);
    
    maintainer->visitResidential(nullptr);
    maintainer->visitCommercial(nullptr);
    maintainer->visitIndustrial(nullptr);
    maintainer->visitLandmark(nullptr);
}

// Test Building Accept Method
TEST_F(VisitorTests, BuildingAcceptMethod) {
    testing::internal::CaptureStdout();
    
    residential->accept(inspector);
    commercial->accept(inspector);
    industrial->accept(inspector);
    landmark->accept(inspector);
    
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Inspecting") != std::string::npos);
} 