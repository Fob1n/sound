/*Contains screen manipulation functions, such as clearScreen()
gotoxy(), setColor(), etc*/
#include "screen.h"
#include <stdio.h>

/*
	*Function definition of clearScreen()
	*This function will use VT100 escape sequence "\ESC[2J" to erase
	 the total terminal screen
	*Input argument: none
	*Return argument: none
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	*Function definition of gotoxy()
	*This function uses VT100 escape sequence "\ESC[row;colH"
	 to set the cursor to the specific location of the terminal screen
	*Input argument:
		int row: row number (1 is top)
		int col: column number (1 is left)
	*Return argument: none
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/*
	*Function definition of bar()
	*This function shows the result in bars
	*Input argument:
		int col: column number to start the bars from the most left
		double dB: the decibel value to get values for the bars
	*Return argument: none
	*RES/UNICODE defined int "screen.h"
*/
void bar(int col, double dB){
	int i;
	for(i=0; i<dB/RES;i++){
		gotoxy(35-i, col+1);	//The first bar start from col=1
#ifndef	UNICODE
		printf("%c", '|');
#else
		if(i<40/RES)	setColor(GREEN);	//All values below 40dB is green
		else if(i<60/RES) setColor(YELLOW);	//All values between 40dB and 60dB is yellow
		else setColor(RED);					//All values above 80dB is red
		printf("%s", BAR);
#endif
	}
	gotoxy(37, 1);
}

/*
	*Function definition of setColor()
	*This function uses VT100 escape sequence "\ESC{1;colorm" to change the color of
	 the bars
	*Input argument:
		int color: color string that is defined in "screen.h"
	*Return argument: none
*/
void setColor(int color){
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}

