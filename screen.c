/*Contains screen manipulation functions, such as clearScreen()
gotoxy(), setColor(), etc*/
#include "screen.h"
#include <stdio.h>

void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

void bar(int col, double dB){
	int i;
	for(i=0; i<dB/RES;i++){
		gotoxy(35-i, col+1);	//The first bar start from col=1
#ifndef	UNICODE
		printf("%c", '|');
#else
		if(i<40/RES)	setColor(GREEN);
		else if(i<60/RES) setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}
}
void setColor(int color){
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}
