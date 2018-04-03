//contains screen manioulation functions, such as chearscreen gotoxy();
//setColor(), etc
#include "screen.h"
#include <stdio.h>

void clearScreen(void){
	printf("%c[2J",ESC);
	fflush(stdout);
}

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);

}

void setColor(int color){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
}

void bar(int col, double dB){
	int i;
	for(i=0; i<dB/4; i++){
		gotoxy(25-i, col);
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i<60/4) setColor(WHITE);
		else if(i<80/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s",BAR);
#endif
	}
}
