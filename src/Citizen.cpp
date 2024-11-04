#include "Citizen.h"
#include <chrono>

Citizen::Citizen(double income)
{
	this->income = income;

	auto now = std::chrono::system_clock::now();
    auto unix_timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    
	this->id = unix_timestamp;

	this->complaints = new int[4];
	this->deliveredResources = new int[4];
}

Citizen::~Citizen()
{
	delete[] this->complaints;
	delete[] this->deliveredResources;

	this->complaints = NULL;
	this->deliveredResources = NULL;
}

int Citizen::issueComplaint() {
	//have an array that corresponds to the resource they get, 0-water, 1-electricity, 2-sewage, 3-waste, 4-none(all zero), 5-all (all equal but not zero)
	if (complaints[0] > complaints[1] && complaints[0] > complaints[2] && complaints[0] > complaints[3])
		return 0;

	if (complaints[1] > complaints[0] && complaints[1] > complaints[2] && complaints[1] > complaints[3])
		return 1;

	if (complaints[2] > complaints[1] && complaints[2] > complaints[0] && complaints[2] > complaints[3])
		return 2;

	if (complaints[3] > complaints[1] && complaints[3] > complaints[2] && complaints[3] > complaints[0])
		return 3;

	if (complaints[0] == 0 && complaints[1] == 0 && complaints[2] == 0 && complaints[3] == 0)
		return 4;

	return 5;
}

void Citizen::resetDelivery()
{
	for (int i = 0; i < 4; i++)
	{
		deliveredResources[i] = 0;
	}
}

int Citizen::deliverResources(int water,int elec,int sewage,int waste)
{
	this->deliveredResources[0] = water;
	this->deliveredResources[1] = elec;
	this->deliveredResources[2] = sewage;
	this->deliveredResources[3] = waste;

	if (this->deliveredResources[0] == 1)
		this->complaints[0]++;

	if (this->deliveredResources[1] == 1)
		this->complaints[1]++;

	if (this->deliveredResources[2] == 1)
		this->complaints[2]++;

	if (this->deliveredResources[3] == 1)
		this->complaints[3]++;

	this->resetDelivery();
}

double Citizen::getSalary()
{
	return this->income;
}

int Citizen::getSatisfaction()
{
	return this->satisfaction;
}

long Citizen::getID()
{
	return this->id;
}