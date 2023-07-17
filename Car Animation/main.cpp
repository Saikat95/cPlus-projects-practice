#include<graphics.h>
#include<windows.h>

main(){
	initwindow(1280,720);
	
	for(int i=0; i<900; ++i){
	
	//road
	line(10,416,1200,416);
	
	//car body
	setcolor(RED);
	
	setfillstyle(SOLID_FILL,YELLOW);
	line(30+i,360,30+i,400);
	line(30+i,360,70+i,360);
	line(70+i,360,90+i,320);
	line(90+i,320,190+i,320);
	line(190+i,320,230+i,360);
	line(230+i,360,300+i,360);
	line(300+i,360,300+i,400);
	//line(300+i,400,30+i,400);
	line(300+i,400,220+i,400);
	arc(200+i,400,0,185,21);
	line(180+i,400,120+i,400);
	arc(100+i,400,0,185,21);
	line(80+i,400,30+i,400);
	floodfill(31+i,390,RED);
	
	//front wheel
	setfillstyle(SOLID_FILL,BLUE);
	circle(200+i,400,16);
	floodfill(200+i,400,RED);
	setfillstyle(SOLID_FILL,BLACK);
	circle(200+i,400,5);
	floodfill(200+i,400,RED);
	//floodfill(200+i,400,BLACK);
	
	//back wheel
	setfillstyle(SOLID_FILL,BLUE);
	circle(100+i,400,16);
	floodfill(100+i,400,RED);
	setfillstyle(SOLID_FILL,BLACK);
	circle(100+i,400,5);
	floodfill(100+i,400,RED);
	
	//back window
	setfillstyle(SOLID_FILL,GREEN);
	line(80+i,360,95+i,330);
	line(95+i,330,140+i,330);
	line(140+i,330,140+i,360);
	line(140+i,360,80+i,360);
	floodfill(81+i,359,RED);
	
	//front window
	setfillstyle(SOLID_FILL,GREEN);
	line(150+i,360,150+i,330);
	line(150+i,330,190+i,330);
	line(190+i,330,215+i,360);
	line(215+i,360,150+i,360);
	floodfill(151+i,359,RED);
	
	delay(1);
	//system("cls");
	
	setcolor(WHITE);
	
	cleardevice();
	
	
	}

	
	getch();
}
