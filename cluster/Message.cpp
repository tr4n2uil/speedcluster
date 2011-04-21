#include "Message.h"

#include <iostream>
using namespace std;

Message::Message(int inId, long inAttime, int inFrom, int inTo, long inSize, Network *inNet)
		: SimUnit(inId, inAttime), from(inFrom), to(inTo), size(inSize), net(inNet) { 
}

// no need
bool Message::simulateTick() {
	return SimUnit::simulateTick();
}

bool Message::nextState() {
	switch(state){
		case SimUnit::YET_TO_BEGIN :
		{
			ticks = net->getStartupTime();
			state = Message::STARTUP_TIME;
			from->switchTransfer(ticks);
			to->switchTransfer(ticks);
			return true;
		}
		case Message::STARTUP_TIME :
		{
			ticks = net->getTransferTime(size, ((from->getClusterId())==(to->getClusterId())));
			state = Message::TRANSFER_TIME;
			from->switchTransfer(ticks);
			to->switchTransfer(ticks);
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
