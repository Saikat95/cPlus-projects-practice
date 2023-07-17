#include<windows.h>
#include<vector>

#define HEIGHT 25
#define WIDTH 50

using namespace std;

class Snake{
	private: 
		COORD pos;
		int len;
		int vel;
		char direction;
		vector<COORD> body;
		
	public:
		Snake(COORD pos, int vel); //initialize values
		void change_direction(char dir); //change the direction of snake
		void move_snake(); //move the snake in particular direction
		COORD get_pos(); //get current position of the snake
		bool eaten(COORD food_pos); //check if the snake eaten the food
		void grow(); //increase length of snake
		bool collided(); //wall collision check
		vector<COORD> get_body(); //body of the snake
};
