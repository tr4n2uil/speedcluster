#include "Cluster.h"

#include <iostream>
using namespace std;

Cluster::Cluster(int inId, long inAttime, long inExectime) : id(inId), attime(inAttime), exectime(inExectime), state(0) { 

}

bool Cluster::simulateTick() {

}