#include <cstdlib>
#include "../../bitvoyager/net/transport/generic.h"
#include "../../bitvoyager/net/transport/stream.h"

#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

	if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <Server IP Address> <Server Port>\n", argv[0]);
        exit(1);
    }
	
	TransportEndpoint *te = new TransportEndpoint(argv[1] , atoi(argv[2]));
	struct sockaddr_in *saddr = te->getLegacyAddress();
	(void) memset(saddr, 0, sizeof(*saddr));
	
	TransportEntity *tp = new StreamTransporter(te);
	if(tp->initialize()<0){
		delete tp;
		return -1;
	}
		
	while(1){
		TransportService *ts = tp->getService();
		if(ts == NULL)
			return -1;
		
		while(1) {
			char *buffer = ts->getBuffer();
			ts->readDataUnit();
			//cout << "DEBUG : read "<<buffer<<" : "<<strncmp(buffer, "BYE", 3)<<"\n";
			if(strncmp(buffer, "BYE", 3) == 0)
				break;
			strcpy(buffer+strlen(buffer)," : Received your message successfully.\n");
			ts->writeDataUnit();
			//cout << "DEBUG : write\n";
		}

		delete(ts);
	}
	
	delete(tp);

	return 0;
}
