#include <cstdlib>
#include "../../bitvoyager/net/transport/generic.h"
#include "../../bitvoyager/net/transport/stream.h"

#include <cstring>
#include<string>
#include <iostream>
#include <ctime>
#include<iomanip>

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

	clock_t startclk;
	clock_t stopclk;
	
    for(int i=10; i<1000; i+=10) {
		double diffms=0;
		//cout<<"DEBUG I = "<<i<<endl;
		
		for(int j=0; j<i; j++) {
			//cout<<"DEBUG J = "<<j<<endl;
			startclk=clock();
			
			TransportEntity *tp = new StreamUser(te);
			if(tp->initialize()<0){
				delete tp;
				return -1;
			}
			
			TransportService *ts = tp->getService();
			if(ts == NULL)
				return -1;

			char *buffer = ts->getBuffer();
			strcpy(buffer,"<param><int>5</int><string>SpeedCluster</string></param>.\n");
			ts->writeDataUnit();
			
			ts->readDataUnit();
			//cout<< "RESPONSE\n" << buffer << "\n";
        
			delete(ts);
			delete(tp);
			
			stopclk=clock();
			double timediff=stopclk-startclk;
			diffms+=(timediff*1000)/CLOCKS_PER_SEC;
		}
		double avgtime=diffms/i;
		cout<<i<<"\t"<<setw(10)<<avgtime<<"\t"<<diffms<<"\n";
	}

    return 0;
}
