#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include <vector>
#include <algorithm>

class Cluster {
	private :
		int id;
		long attime;
		long exectime;
		std::vector<int> members;
		
	protected :
		int state;
		static const int YET_TO_BEGIN = 0;
		static const int EXECUTION_TIME = 1;
		static const int COMPLETED = 2;
		long ticks;
		
	public :
		Cluster() : state(0), ticks(0) { }
		Cluster(int inId, long inAttime, long inExectime);
		bool contains(int member) { return std::find(members.begin(), members.end(), member) != members.end(); }
		int getId() { return id; }
		long getAttime() { return attime; }
		long getExectime() { return exectime; }
		int getState() { return state; }
		long getTicks() { return ticks; }
		bool simulateTick();
		~Cluster() { }
	
};

#endif // __CLUSTER_H__
