#include<graphics.h>
#include<iostream>

int main(){
	
	initwindow(800,720);
	
	circle(400,360,10);
	circle(400,360,20);
	circle(400,360,30);
	circle(400,360,40);
	
	for(int i=40; i<340; i +=10){
		circle(400,360,(i+10));
	}
	
	getch();
	
	return 0;
}
