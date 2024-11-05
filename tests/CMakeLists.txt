# Create test executable
add_executable(city_tests
    BuildingTests.cpp
    CityManagerTests.cpp
    ZoneTests.cpp
    CommercialTests.cpp
    IndustrialTests.cpp
    LandmarkTests.cpp
    ZoneManagerTests.cpp
    PolicyTests.cpp
    GovernmentStatisticsTests.cpp
    VisitorTests.cpp
    PolicyMementoTests.cpp
    GovernmentTests.cpp
    RoadTests.cpp
    # Add all your test files here
)

# Link against Google Test and your library
target_link_libraries(city_tests
    PRIVATE
    GTest::GTest
    GTest::Main
    CityLib
)

# Add tests to CTest
add_test(NAME city_tests COMMAND city_tests)