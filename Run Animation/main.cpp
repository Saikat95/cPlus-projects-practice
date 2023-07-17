#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#define SIZE 60

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand(time(NULL));
	char ch;
	cout<<"Enter Letter to begin: ";	
	cin>>ch;
	
	int pos = 0;
	
	while(true){
		cout<<"||Start||";
		
		for(int i=0; i<SIZE; ++i){
			if(i == pos){
				cout<<ch;
			}
			else{
				cout<<" ";
			}
		}
		cout<<"||FINISH||"<<endl;
		
		int move = rand()%3+1;
		
		pos = move + pos;
		
		if(pos<1){
			cout<<"You couldn't finish the race."<<endl;
			break;
		}
		
		if(pos > (SIZE-1)){
			cout<<"Yay!!!! You completed the track"<<endl;
			break;
		}
		for(int sleep = 0; sleep < 10000000; ++sleep);
		for(int sleep = 0; sleep < 10000000; ++sleep);	
		for(int sleep = 0; sleep < 10000000; ++sleep);	

	}
	
	return 0;
}
