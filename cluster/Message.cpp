#include "Message.h"

#include <iostream>
using namespace std;

Message::Message(int inId, long inAttime, Task *inFrom, Task *inTo, long inSize, Network *inNet)
		: SimUnit(inId, inAttime), from(inFrom), to(inTo), size(inSize), net(inNet) { 
}

// no need
bool Message::simulateTick() {
	return SimUnit::simulateTick();
}

bool Message::nextState() {
	//cout << "Message "<<id<<" State Changed\n";
	switch(state){
		case SimUnit::YET_TO_BEGIN :
		{
			ticks = net->getStartupTime();
			state = Message::STARTUP_TIME;
			from->switchTransfer(ticks+1);
			to->switchTransfer(ticks+1);
			return true;
		}
		case Message::STARTUP_TIME :
		{
			if((from->getClusterId()) == 0 || (to->getClusterId()) == 0)
				ticks = net->getTransferTime(size, false);
			else
				ticks = net->getTransferTime(size, ((from->getClusterId())==(to->getClusterId())));
			state = Message::TRANSFER_TIME;
			from->switchTransfer(ticks+1);
			to->switchTransfer(ticks+1);
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
