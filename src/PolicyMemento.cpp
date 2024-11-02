#include "PolicyMemento.h"

PolicyMemento::PolicyMemento(int rate) {
	this->taxRate = rate;
}

int PolicyMemento::getTaxRate() {
	return this->taxRate;
}
