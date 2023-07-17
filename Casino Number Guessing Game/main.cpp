#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void rules();

int main(int argc, char** argv) {
	cout<<"WELCOME TO CASIONO";
	cout<<"\n================================";
	rules();
		
	char ch;
	double balance, bet;
	int num;
	
	do{
		system("cls");
		cout<<"GAME";
		cout<<"\n====================";
		cout<<"\n\nEnter your balance: ";
		cin>>balance;
		srand(time(0));
		int dice = rand()%10 +1;
		
		do{
			cout<<"\nEnter your Bet: ";
			cin>>bet;
			cout<<"Enter the Number: ";
			cin>>num;
			
			if(num == dice){
				cout<<"\n\nCongratulations!!!! You have won.";
				balance += bet*10;
			}
			else{
				cout<<"The number was: "<<dice;
				cout<<"\n\nBetter luck next time";
				balance -= bet;
			}
			
			cout<<"\nYour balance is: "<<balance;
			
			cout<<"\n\nDo you want to play again(y/n)?";
			cin>>ch;
			
		} while(ch == 'y' || ch == 'Y');
		
		
	} while(balance > 0	);
	
	cout<<"\n\n\t\tTHANK YOU FOR PLAYING CASINO";
	
	return 0;
}

void rules(){
	cout<<"\nRules of the game";
	cout<<"\n---------------------------";
	cout<<"\n1. Bet minjmum of Rs. 100";
	cout<<"\n2. Guess the number and win 10x the amount";
	cout<<"\n3. No violence";
	cout<<"\nHappy Playing\n";
	getch();
}
