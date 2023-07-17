#include<graphics.h>

main(){
	initwindow(800,720);
	
	for(int i=10; i<340; i += 10){
		line(300-i,320-i,500+i,320-i);
		line(300-i,400+i,500+i,400+i);
		line(300-i,320-i,300-i,400+i);
		line(500+i,320-i,500+i,400+i);
	}

	getch();
}
