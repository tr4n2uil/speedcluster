#include "../simulator.h"
#include "../cluster.h"

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	Engine eng;
	vector<Task *> tasks;
	int tsknum, msgnum, cstnum;
	
	cout << "FORMAT" << endl;
	cout << "<number_of_tasks>" << endl;
	cout << "<task_id (index start from 0)> <task_start_time> <task_execution_time>" << endl;
	cout << "<number_of_messages>" << endl;
	cout << "<msg_id> <msg_start_time> <msg_from_id> <msg_to_id> <msg_size>" << endl;
	cout << "<number_of_clusters>" << endl;
	cout << "<cst_id> <cst_start_time> <cst_end_time> <task_count> <task_ids ...>" << endl;
	
	cin >> tsknum;
	for(int i=0; i<tsknum; i++){
		int id;
		long attime, exectime;
		cin >> id >> attime >> exectime;
		Task *t = new Task(id, attime, exectime);
		tasks.push_back(t);
	}
	
	cin >> msgnum;
	Network net(15, 10, 0.5);
	for(int i=0; i<msgnum; i++){
		int id, from, to;
		long attime, size;
		cin >> id >> attime >> from >> to >> size;
		Message *m = new Message(id, attime, tasks[from], tasks[to], size, &net);
		eng.addUnit(m);
	}
	
	cin >> cstnum;
	for(int i=0; i<cstnum; i++){
		int id, count;
		long attime, fortime;
		cin >> id >> attime >> fortime >> count;
		Cluster *c = new Cluster(id, attime, fortime);
		for(int j=0; j < count; j++){
			int index;
			cin >> index;
			c->addTask(tasks[index]);
		}
		eng.addUnit(c);
	}
	
	for(int i=0; i<tsknum; i++)
		eng.addUnit(tasks[i]);
	
	long 	ticks = 0;
	while(eng.run()){
		ticks++;
		cout << "TICK : " << ticks << endl;
	}
	
	return 0;
}