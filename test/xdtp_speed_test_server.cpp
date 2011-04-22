#include <cstdlib>
#include "../../bitvoyager/net/application/generic.h"
#include "../../bitvoyager/net/application/xdtp.h"

#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	
	ApplicationEntity *ap = new XdtpBaseServer(new XdtpEndpoint(atoi(argv[1])));
	if(ap->initialize()<0){
		delete ap;
		return -1;
	}
	
	while(1) {
		ApplicationSession *as = ap->getSession();
		if(as == NULL)
			return -1;
		
		int status = as->readMessage();
		status = as->generateNext();
		if( status == 0 ) {
			delete(as);
			delete(ap);
			return 0;
		}
		else {
			as->writeMessage();
		}
		
		delete(as);
	}
	
	delete(ap);

	return 0;
}
