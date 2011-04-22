#include <cstdlib>
#include "../../bitvoyager/net/application/generic.h"
#include "../../bitvoyager/net/application/xdtp.h"

#include <cstring>
#include<string>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){
	
	clock_t startclk;
	clock_t stopclk;
	
	for(int i=0; i<100; i++) {
        double diffms=0;
		
        for(int j=0; j<i; j++) {
			startclk=clock();
			
			ApplicationEntity *ap = new XdtpBaseClient(new XdtpEndpoint(atoi(argv[1])));
			if(ap->initialize()<0){
				delete ap;
				return -1;
			}
	
			ApplicationSession *as = ap->getSession();
			if(as == NULL)
				return -1;

			MessageComponent **message;	
			char *buffer="GET /Google.html";;
			
			string msg(buffer);
			int status = as->generate(msg);
			if ( status < 0 ){
				delete(as);
				delete(ap);
				return 0;
			}
			
			status = as->writeMessage();
			if ( status < 0 ){
				delete(as);
				delete(ap);
				return 0;
			}
			
			status = as->readMessage();
			if ( status < 0 ){
				delete(as);
				delete(ap);
				return 0;
			} else {
				message = as->getMessage();
				//cout<<"Response\n"<<(*message)->getString()<<"\n";
			}	
			
			delete(as);
			delete(ap);
			
			stopclk=clock();
			double timediff=stopclk-startclk;
			diffms+=(timediff*1000)/CLOCKS_PER_SEC;
        }
        double avgtime=diffms/(i+1);
        cout<<i+1<<"\t"<<avgtime<<"\n";
	}
    return 0;
}
