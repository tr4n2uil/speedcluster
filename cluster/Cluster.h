#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "../simulator/SimUnit.h"
#include "Task.h"

#include <vector>
#include <algorithm>

class Cluster : public SimUnit {
	private :
		long fortime;
		std::vector<Task*> members;
		
	protected :
		static const int ACTIVE_TIME = 2;
		
	public :
		Cluster() : SimUnit() { }
		Cluster(int inId, long inAttime, long inFortime);
		bool contains(Task *member) { return std::find(members.begin(), members.end(), member) != members.end(); }
		long getFortime() { return fortime; }
		void addTask(Task *t) { members.push_back(t); }
		bool simulateTick();
		bool nextState();
		~Cluster() { }
	
};

#endif // __CLUSTER_H__
