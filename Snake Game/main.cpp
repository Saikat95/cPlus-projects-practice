#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<ctime>

#include "Snake.h"
#include "Food.h"

#define HEIGHT 25
#define WIDTH 50

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;
int score = 0;

void board(){
	
	COORD snake_pos = snake.get_pos();
	COORD food_pos = food.get_pos();
	vector<COORD> snake_body = snake.get_body();
	
	cout<<"\t\t\t\t\t    Welcome to the Snake World\n";
	cout<<"\t\t\t\t--------------------------------------------------\n\n";
	cout<<"\t\t\t\t\t\t    Score: "<<score<<"\n\n";
		
	for(int i=0; i<HEIGHT; ++i){
		cout<<"\t\t\t\t#";
		for(int j=0; j<WIDTH-2; ++j){
			if(i == 0 || i == HEIGHT-1){
				cout<<"#";
			}
			
			else if(i == snake_pos.Y && j+1 == snake_pos.X){
				cout<<"0";
			}
			
			else if(i == food_pos.Y && j+1 == food_pos.X){
				cout<<"@";
			}
			
			else{
				bool isBodyPart = false;
				for(int k=0; k<snake_body.size()-1; ++k){
					if(i == snake_body[k].Y && j+1 == snake_body[k].X){
						cout<<"o";
						isBodyPart = true;
						break;
					}
				}
				if(!isBodyPart){
					cout<<" ";
				}
			}
		}
		
		cout<<"#\n";
	}
}

void game() {
	
	srand(time(NULL));
	bool game_over = false;
	
	while(!game_over){
		board();
		if(kbhit()){
			switch(getch()){
				case 'w': snake.change_direction('u'); break;
				case 's': snake.change_direction('d'); break;
				case 'a': snake.change_direction('l'); break;
				case 'd': snake.change_direction('r'); break;
			}
		}
		
	
		
		if(snake.eaten(food.get_pos())){
			food.gen_food();
			snake.grow();
			score++;
		}
		
		snake.move_snake();
		
		if(snake.collided()){
			game_over = true;
		}
		
		
			
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});

		//system("cls");
		
	}
	
}

int main(int argc, char** argv){
	
	bool playGame = true;
	
	while(playGame){
		
		char choice;
		
		game();
		
		cout<<"Do you want to play again?(Y/N)"; cin>>choice;
		if(choice == 'y' || choice == 'Y'){
			playGame = true;
		}
		
		else if(choice == 'n' || choice == 'N'){
			playGame = false;
		}
		
		else{
			cout<<"Invalid Choice\n";
			cout<<"Please select y or n: "; cin>>choice;
		}
		
	}
	
	return 0;
}
