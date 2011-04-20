#include "Task.h"

#include <iostream>
using namespace std;

Task::Task(int inId, long inAttime, long inExectime) : id(inId), attime(inAttime), exectime(inExectime), state(0) { 

}

bool Task::simulateTick() {

}