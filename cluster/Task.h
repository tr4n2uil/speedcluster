#ifndef __TASK_H__
#define __TASK_H__

#include "../simulator/SimUnit.h"

class Task  : public SimUnit{
	private :
		long exectime;
		bool clusteractive;
	
	protected :
		static const int EXECUTION_TIME = 2;
		static const int TRANSFER_TIME = 3;
		long execticks;
		
	public :
		Task() : SimUnit(), exectime(0), clusteractive(0), execticks(0) { }
		Task(int inId, long inAttime, long inExectime, bool inClusteractive = false);
		long getExectime() { return exectime; }
		long getExecticks() { return execticks; }
		bool simulateTick();
		bool nextState();
		~Task() { }
};

#endif // __TASK_H__