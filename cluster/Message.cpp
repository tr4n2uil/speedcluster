#include "Message.h"

#include <iostream>
using namespace std;

Message::Message(int inFrom, int inTo, long inAttime, long inSize) : from(inFrom), to(inTo), attime(inAttime), size(inSize), state(0) { 

}

bool Message::simulateTick() {

}