#ifndef __MESSAGE_H__
#define __MESSAGE_H__

class Message {
	private :
		int from;
		int to;
		long attime;
		long size;
	
	protected :
		int state;
		const int YET_TO_BEGIN = 0;
		const int STARTUP_TIME = 1;
		const int TRANSFER_TIME = 2;
		const int COMPLETED = 3;
		long ticks;
		
	public :
		Message() : from(0), to(0), attime(0), size(0), state(0), ticks(0) { }
		Message(int inFrom, int inTo, long inAttime, long inSize);
		int getFrom() { return from; }
		int getTo() { return to; }
		long getAttime() { return attime; }
		long getFortime() { return fortime; }
		int getState() { return state; }
		long getTicks() { return ticks; }
		bool simulateTick();
		~Message() { }
};

#endif // __MESSAGE_H__