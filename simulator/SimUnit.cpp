#include "SimUnit.h"

#include <iostream>
using namespace std;

bool SimUnit::simulateTick() {
	if(state == SimUnit::COMPLETED)
		return false;
	if(! (--ticks))
		return nextState();
	return true;
}
