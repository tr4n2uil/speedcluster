#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "../simulator/SimUnit.h"
#include "../simulator/Network.h"
#include "Task.h"

class Message : public SimUnit {
	private :
		Task *from;
		Task *to;
		long size;
		Network *net;
	
	public :
		static const int STARTUP_TIME = 2;
		static const int TRANSFER_TIME = 3;
		
	public :
		Message() : SimUnit(), from(0), to(0), size(0), net(0) { }
		Message(int inId, long inAttime, Task *inFrom, Task *inTo, long inSize, Network *net);
		Task *getFrom() { return from; }
		Task *getTo() { return to; }
		long getSize() { return size; }
		bool simulateTick();
		bool nextState();
		~Message() { }

};

#endif // __MESSAGE_H__