#ifndef POLICYMEMENTO_H
#define POLICYMEMENTO_H

class PolicyMemento {
private:
	int taxRate;

public:
	PolicyMemento(int rate);

	int getTaxRate();
};

#endif
