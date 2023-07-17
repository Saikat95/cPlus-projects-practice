#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<conio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_TRIES 5

int letterGuess(char, string, string&);

int main(int argc, char** argv) {
	char letter;
	int wrong_guess = 0;
	string word;
	string words[10] = {"india","pakistan","australia","japan","china","netherland","greenland","mexixo","morocco","brazil"};
	
	srand(time(NULL));
	int n = rand()%10;
	word = words[n];
	
	string unknown(word.length(),'*');
	
	cout<<"\n\nWELCOME TO HANGMAN";
	cout<<"\n=============================";
	cout<<"\n\nThe letters of the word are hidden. Guess the letters and save hangman";
	cout<<"\nYou have "<<MAX_TRIES<<" attempts. All the best !!!!!!!!!";
	cout<<"\n\n\t"<<unknown;
	
	while(wrong_guess < MAX_TRIES){
		cout<<"\n\nEnter a letter: ";
		cin>>letter;
		if(letterGuess(letter,word,unknown) == -1){
			cout<<"\nAlready Guessed";
		}
		
		else if(letterGuess(letter,word,unknown) == 0){
			cout<<"\nWhoops!!! Letter is not there ";
			wrong_guess++;
		}
		
		
		else{
			cout<<"\nGood!!! You guessed the letter: ";
			cout<<unknown;
		}
		
		cout<<"\nGuess left: "<<MAX_TRIES-wrong_guess;
		
		if(word == unknown){
			cout<<"\n\n\n\tCongrats!!! You have guessed the word.";
			cout<<"\n\t  The word is: "<<unknown;
			break;
		}
		
		if(wrong_guess == MAX_TRIES){
			cout<<"\n\n\n\tSorry!!! You lost.";
			cout<<"\n\t The word was: "<<word;
		}
		
	}
	
	getch();
	
	return 0;
}

int letterGuess(char guess, string word, string &guessword){
	int match = 0;
	int len = word.length();
	
	for(int i=0; i<len; i++){
		if(guess == guessword[i]){
			return -1;
		}
		
		if(guess == word[i]){
			guessword[i] = guess;
			match++;
		}
	}
	
	return match;
}

