#include "Engine.h"

#include <iostream>
using namespace std;

int Engine::run() {
	int val = 0;
	for(vector<SimUnit*>::iterator p=units.begin(); p!=units.end(); p++)
		val += (*p)->simulateTick();
	return val;
}
