#include "Network.h"

#include <iostream>
using namespace std;

long Network::getStartupTime() {
	return startup;
}

long Network::getTransferTime(long size, bool clusteractive) {
	if(clusteractive)
		return fraction * size / cost;
	return size / cost;
}