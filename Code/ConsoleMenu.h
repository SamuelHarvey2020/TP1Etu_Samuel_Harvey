#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void Run();

private:
	char ReadValidInput(char tabValidInputs[], int nbElements);
	void DisplayMenu();
	void DisplayCredits();
	bool ManageSelection(char entry);
};

