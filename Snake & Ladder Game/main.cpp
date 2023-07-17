#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int diceOne();
int diceTwo();
void position(int&,int);
void gamescore(char[],char[],int,int);
void board();

int main(int argc, char** argv) {
	char playerOne[20], playerTwo[20];
	int playerOneScore = 0, playerTwoScore = 0;
	srand(time(NULL));
	
	cout<<"\t\t    WELCOM TO THE WORLD OF SNAKES";
	cout<<"\n\t\t=====================================\n";
	cout<<"\nEnter player one name: ";
	cin.get(playerOne, 20);
	cin.ignore();
	cout<<"Enter player two name: ";
	cin.get(playerTwo,20);
	
	board();


	while(playerOneScore <= 100 && playerTwoScore <= 100){
		int diceUp;
		
		gamescore(playerOne,playerTwo,playerOneScore,playerTwoScore);
		
		cout<<"\n\nPlayer One Roll the dice";
		getch();
		diceUp = diceOne();
		cout<<"\nDice up: "<<diceUp;
		position(playerOneScore,diceUp);
		
		cout<<"\n\nPlayer Two Roll the dice";
		getch();
		diceUp = diceTwo();
		cout<<"\nDice up: "<<diceUp;
		position(playerTwoScore,diceUp);
		
			getch();
			system("cls");
			
		if(playerOneScore == 100){
			cout<<"\n\nCONGRATULATIONS "<<playerOne<<".YOU HAVE WON!!!!!!\n\n";
			break;
		}
		
		else if(playerTwoScore == 100){
			cout<<"\n\nCONGRATULATIONS "<<playerTwo<<".YOU HAVE WON!!!!!!\n\n";
			break;
		}	
	}

	return 0;
}

void board(){
	cout<<"\nRules of the Game";
	cout<<"\n1. Roll the dice";
	cout<<"\n2. Player reaches 100 wins";
	
	cout<<"\n3 Snakes are at positions";
	cout<<"\n\t 97 --> 12";
	cout<<"\n\t 82 --> 22";
	cout<<"\n\t 68 --> 4";
	cout<<"\n\t 61 --> 3";
	cout<<"\n\t 52 --> 11";
	cout<<"\n\t 42 --> 16";
	cout<<"\n\t 32 --> 8";
	
	cout<<"\n3 Ladders are at positions";
	cout<<"\n\t 5 --> 48";
	cout<<"\n\t 9 --> 30";
	cout<<"\n\t 20 --> 39";
	cout<<"\n\t 25 --> 58";
	cout<<"\n\t 36 --> 95";
	cout<<"\n\t 41 --> 79";
	cout<<"\n\t 49 --> 71";	
	cout<<"\n\t 64 --> 99";
	cout<<"\n\t 69 --> 94";	
	
	getch();
	
	system("cls");
}

int diceOne(){

	int number;
	number = rand()%6 + 1;
	return number;
}

int diceTwo(){
	int number;
	number = rand()%6 + 1;
	return number;
}

void position(int &score, int dice){
	score += dice;
	cout<<"\nYou are at position: "<<score;
	
	if(score >100){
		score -= dice;
	}
	
	switch(score){
		case 97: cout<<"\nYou have been caught by Snake at 98";
					score = 12;
					break;
		case 82: cout<<"\nYou have been caught by Snake at 82";
					score = 22;
					break;
		case 68: cout<<"\nYou have been caught by Snake at 68";
					score = 4;
					break;
		case 61: cout<<"\nYou have been caught by Snake at 61";
					score = 3;
					break;
		case 52: cout<<"\nYou have been caught by Snake at 52";
					score = 11;
					break;
		case 42: cout<<"\nYou have been caught by Snake at 42";
					score = 16;
					break;
		case 32: cout<<"\nYou have been caught by Snake at 32";
					score = 8;
					break;
		case 5: cout<<"\nYou have found a ladder. climb to 48";
					score = 48;
					break;
		case 9: cout<<"\nYou have found a ladder. climb to 30";
					score = 30;
					break;
		case 20: cout<<"\nYou have found a ladder. climb to 39";
					score = 39;
					break;
		case 25: cout<<"\nYou have found a ladder. climb to 58";
					score = 58;
					break;
		case 36: cout<<"\nYou have found a ladder. climb to 95";
					score = 95;
					break;
		case 41: cout<<"\nYou have found a ladder. climb to 79";
					score = 79;
					break;
		case 49: cout<<"\nYou have found a ladder. climb to 71";
					score = 71;
					break;
		case 64: cout<<"\nYou have found a ladder. climb to 99";
					score = 99;
					break;
		case 69: cout<<"\nYou have found a ladder. climb to 94";
					score = 94;
					break;
	}
}

void gamescore(char playerOne[20], char playerTwo[20], int scoreOne, int scoreTwo){
	cout<<"\n\t\tPLAY THE GAME";
	cout<<"\n========================================";
	cout<<"\n\t\tGAME STATUS";
	cout<<"\n----------------------------------------";
	cout<<"\n-->"<<playerOne<<"'s Score"<<" = "<<scoreOne;
	cout<<"\n-->"<<playerTwo<<"'s Score"<<" = "<<scoreTwo;
	cout<<"\n";	
	getch();
}
