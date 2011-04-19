#ifndef __TASK_H__
#define __TASK_H__

class Task {
	private :
		int id;
		long attime;
		long exectime;
	
	protected :
		int state;
		const int YET_TO_BEGIN = 0;
		const int EXECUTION_TIME = 1;
		const int TRANSFER_TIME = 2;
		const int COMPLETED = 3;
		long execticks;
		long ticks;
		
	public :
		Task() : id(0), attime(0), exectime(0), state(0), execticks(0), ticks(0) { }
		Task(int inFrom, long inAttime, long inExectime);
		int getId() { return id; }
		long getAttime() { return attime; }
		long getExectime() { return exectime; }
		int getState() { return state; }
		long getTicks() { return ticks; }
		long getExceticks() { return execticks; }
		bool simulateTick();
		~Task() { }
};

#endif // __TASK_H__