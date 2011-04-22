#ifndef __TASK_H__
#define __TASK_H__

#include "../simulator/SimUnit.h"

class Task  : public SimUnit{
	private :
		long exectime;
		int clusterid;
	
	protected :
		long execticks;
	
	public :
		static const int EXECUTION_TIME = 2;
		static const int TRANSFER_TIME = 3;
		
	public :
		Task() : SimUnit(), exectime(0), clusterid(0), execticks(0) { }
		Task(int inId, long inAttime, long inExectime, int inClusterid = 0);
		long getExectime() { return exectime; }
		long getExecticks() { return execticks; }
		int getClusterId() { return clusterid; }
		void setClusterId(int inId) { clusterid = inId; }
		bool simulateTick();
		bool nextState();
		bool switchTransfer(long tfticks);
		~Task() { }
};

#endif // __TASK_H__