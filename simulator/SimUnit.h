#ifndef __SIMUNIT_H__
#define __SIMUNIT_H__

class SimUnit {
	private :
	
	protected :
		int id;
		long attime;
		int state;
		long ticks;
	
	public :
		static const int YET_TO_BEGIN = 0;
		static const int COMPLETED = 1;
		
	public :
		SimUnit(int inId = 0, long inAttime = 0) : id(inId), attime(inAttime), state(0), ticks(0) { ticks = attime; }
		int getId() { return id; }
		long getAttime() { return attime; }
		int getState() { return state; }
		long getTicks() { return ticks; }
		bool simulateTick();
		virtual bool nextState() = 0;
		~SimUnit() { }
};

#endif // __SIMUNIT_H__