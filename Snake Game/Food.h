#include<windows.h>
#include<cstdlib>

#define HEIGHT 25
#define WIDTH 50

class Food{
	private:
		COORD pos;
		
	public:
		Food();
		void gen_food();
		COORD get_pos();	
};
