#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include "Point.h"
#include "Building.h"

class Citizen {
public:
	// Constructor & Destructor
	Citizen(const std::string& name, int age);
	virtual ~Citizen() = default;

	// Basic citizen management
	void update();
	double getHappiness() const;
	bool hasHome() const { return residence != nullptr; }

	// Location and movement
	void moveTo(const Point& newLocation);
	Point getLocation() const { return location; }
	double getSpeed() const { return speed; }

	// Housing
	void setResidence(Building* building);
	Building* getResidence() const { return residence; }
	void notifyBuildingConditionChanged(Building* building);

	// Status and attributes
	std::string getName() const { return name; }
	int getAge() const { return age; }
	bool isHealthy() const { return health > 0.5; }
	double getHealth() const { return health; }
	void adjustHealth(double amount);

private:
	// Basic attributes
	std::string name;
	int age;
	double health{1.0};
	double happiness{0.5};
	double speed{1.0};

	// Location
	Point location;
	Point destination;

	// Housing
	Building* residence{nullptr};

	// Private utility methods
	void updateHappiness();
	void validateHealth();
	bool shouldMove() const;
	void handleBuildingCondition(Building* building);
};

#endif // CITIZEN_H
