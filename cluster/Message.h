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
		static const int YET_TO_BEGIN = 0;
		static const int STARTUP_TIME = 1;
		static const int TRANSFER_TIME = 2;
		static const int COMPLETED = 3;
		long ticks;
		
	public :
		Message() : from(0), to(0), attime(0), size(0), state(0), ticks(0) { }
		Message(int inFrom, int inTo, long inAttime, long inSize);
		int getFrom() { return from; }
		int getTo() { return to; }
		long getAttime() { return attime; }
		long getSize() { return size; }
		int getState() { return state; }
		long getTicks() { return ticks; }
		bool simulateTick();
		~Message() { }
};

#endif // __MESSAGE_H__