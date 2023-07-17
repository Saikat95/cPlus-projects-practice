#include <iostream>
#include <cstring>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

bool isNumber(string number){
	for(int i=0; i<number.length(); ++i){
		if(number[i] < '0' || number[i] > '9'){
			return false;
		}
	}
	
	return true;
}

int main(int argc, char** argv) {
	string ccNumber;
	
	while(true){
		cout<<"\nEnter CC number to validate: ";
		cin>>ccNumber;
		
		if(ccNumber == "exit"){
			break;
		}
		
		else if(!isNumber(ccNumber)){
			cout<<"\nBad Input";
			continue;
		}
		
		int len = ccNumber.length();
		int doubleEvenSum = 0;
		
		for(int i = len - 2; i>=0; i = i - 2){
			int dbl = ((ccNumber[i] - '0') * 2);
			if(dbl > 9){
				dbl = (dbl/10) + (dbl%10);
			}
			
			doubleEvenSum += dbl;
		}
		
		for(int i = len-1; i>=0; i = i-2){
			doubleEvenSum += (ccNumber[i] - 48);
		}
		
		bool result = (doubleEvenSum%10 == 0);
		
		cout << "Result: "<<(result ? "Valid" : "Invalid")<<endl;
	}
	
	return 0;
}
