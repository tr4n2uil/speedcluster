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
			for(vector<Task*>::iterator p=members.begin(); p!=members.end(); p++)
				p->setClusterId(id);
			return true;
		}
		case Cluster::ACTIVE_TIME :
		{
			state = SimUnit::COMPLETED;
			for(vector<Task*>::iterator p=members.begin(); p!=members.end(); p++)
				p->setClusterId(0);
			return true;
		}
		case SimUnit::COMPLETED :
		default :
		{
			return false;
		}
	}
}
