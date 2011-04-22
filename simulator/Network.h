#ifndef __NETWORK_H__
#define __NETWORK_H__

class Network {
	protected :
		long cost;
		float fraction;
		long startup;
	
	public :
		Network(long startup = 15, long cost = 10, float fraction = 0.8) : startup(startup), cost(cost), fraction(fraction) { }
		long getStartupTime();
		long getTransferTime(long size, bool clusteractive = false);
		~Network() { }
};

#endif // __NETWORK_H__
