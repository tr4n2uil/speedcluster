#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "SimUnit.h"
#include <vector>

class Engine {
	protected :
		std::vector<SimUnit*> units;
	
	public :
		Engine() { }
		void addUnit(SimUnit *unit) { units.push_back(unit); }
		int run();
		~Engine() { }
};

#endif // __ENGINE_H__
