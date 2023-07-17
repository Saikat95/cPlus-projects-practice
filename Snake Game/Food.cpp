#include "Food.h"

Food::Food(){
	gen_food();
}

void Food::gen_food(){
	//[u,l] = rand() % (u - l + 1) + l
	pos.X = (rand() % (WIDTH - 3)) + 1;
	pos.Y = (rand() % (HEIGHT - 3)) + 1;
}

COORD Food::get_pos(){
	return pos;
}
