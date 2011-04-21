#include "Task.h"

#include <iostream>
using namespace std;

Task::Task(int inId, long inAttime, long inExectime, bool inClusteractive) : SimUnit(inId, inAttime), exectime(inExectime), clusteractive(inClusteractive) { 
}

// no need
bool Task::simulateTick() {
	return SimUnit::simulateTick();
}

bool Task::nextState() {
	switch(state){
		case SimUnit::YET_TO_BEGIN :
		{
			ticks = exectime;
			state = Task::EXECUTION_TIME;
			return true;
		}
		case Task::TRANSFER_TIME :
		{
			ticks = execticks;
			state = Task::EXECUTION_TIME;
			return true;
		}
		case Task::EXECUTION_TIME :
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
