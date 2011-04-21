#include "Task.h"

#include <iostream>
using namespace std;

Task::Task(int inId, long inAttime, long inExectime, int inClusterid) : SimUnit(inId, inAttime), exectime(inExectime), clusterid(inClusterid) { 
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

bool Task::switchTransfer(long tfticks) {
	execticks = ticks;
	ticks = tfticks;
	state = Task::TRANSFER_TIME;
	return true;
}
