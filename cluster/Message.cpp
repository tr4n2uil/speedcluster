#include "Message.h"

#include <iostream>
using namespace std;

Message::Message(int inId, long inAttime, int inFrom, int inTo, long inSize)
		: SimUnit(inId, inAttime), from(inFrom), to(inTo), size(inSize) { 
}

// no need
bool Message::simulateTick() {
	return SimUnit::simulateTick();
}

bool Message::nextState() {
	switch(state){
		case SimUnit::YET_TO_BEGIN :
		{
			// TODO set ticks
			state = Message::STARTUP_TIME;
			return true;
		}
		case Message::STARTUP_TIME :
		{
			// TODO set ticks
			state = Message::TRANSFER_TIME;
			return true;
		}
		case Message::TRANSFER_TIME :
		{
			state = SimUnit::COMPLETED;
			return true;
		}
		case SimUnit::COMPLETED :
		default :
		{
			return false;
		}
	}
}
