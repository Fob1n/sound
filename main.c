#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sound.h"

/*
 *Function definition of main()
 *This function records audio for a second and saves the information into "test.wav"
  It also displays the information bar.
 *Input argument: none
 *Return argument: integer
*/
int main(void){
	int ret;
	while(1){
		//Record 1 sec of sound into test.wav
		ret = system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT))break;
		//Open the wav file and read samples
		//Display necessary information (duration, wav header etc)
		clearScreen();
		displayWAVheader("test.wav");

		//Calculate fast dBs
		displayBar("test.wav");
		//Send fast dBs to web (php program on www.cc.puv.fi)
//		break;	//For testing, just run the loop once
	}
}
