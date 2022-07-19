// ExAdapterPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// Target
class IPlug {
public:
	virtual void pinCount() = 0;
	virtual void roundPin() = 0;
};

class ConcretePlug : public IPlug {
public:
	void pinCount() {
		cout << "I am a two pin" << endl;
	}
	void roundPin() {
		cout << "I am a round pin" << endl;
	}
};

// Adaptee
class ISwitchBoard {
public:
	virtual void pinCount() = 0;
	virtual void flatPin() = 0;
};

class ConcreteSwitchBoardPlug : public ISwitchBoard {
public:
	void pinCount() {
		cout << "I am a three pin" << endl;
	}
	void flatPin() {
		cout << "I am a flat pin" << endl;
	}
};

class Adapter : public IPlug {
	ISwitchBoard* switchBoard{ nullptr };
public:
	Adapter(ISwitchBoard* ref) : switchBoard(ref) {
	}

	void pinCount() {
		if (switchBoard) {
			switchBoard->pinCount();
		}
	}

	void roundPin() {
		if (switchBoard) {
			switchBoard->flatPin();
		}
	}
};

int main()
{
	ISwitchBoard* ref = new ConcreteSwitchBoardPlug();

	Adapter adapter(ref);
	adapter.pinCount();
	adapter.roundPin();
	cin.get();
	return 0;
}