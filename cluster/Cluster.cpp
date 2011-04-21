#include "Cluster.h"

#include <iostream>
using namespace std;

Cluster::Cluster(int inId, long inAttime, long inFortime) : SimUnit(inId, inAttime), fortime(inFortime) { 
}

// no need
bool Cluster::simulateTick() {
	return SimUnit::simulateTick();
}

bool Cluster::nextState() {
	switch(state){
		case SimUnit::YET_TO_BEGIN :
		{
			ticks = fortime;
			state = Cluster::ACTIVE_TIME;
			return true;
		}
		case Cluster::ACTIVE_TIME :
		{
			state = SimUnit::COMPLETED;
			return true;
		}
		case SimUnit::COMPLETED :
		default :
		{
			return false;
		}
	}
}
