#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "../simulator/SimUnit.h"

class Message : public SimUnit {
	private :
		int from;
		int to;
		long size;
	
	protected :
		static const int STARTUP_TIME = 2;
		static const int TRANSFER_TIME = 3;
		
	public :
		Message() : SimUnit(), from(0), to(0), size(0) { }
		Message(int inId, long inAttime, int inFrom, int inTo, long inSize);
		int getFrom() { return from; }
		int getTo() { return to; }
		long getSize() { return size; }
		bool simulateTick();
		bool nextState();
		~Message() { }

};

#endif // __MESSAGE_H__