#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

int main(void){
	while(1){
		//Record 1 sec of sound into test.wav
		system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		//Open the wav file and read samples
		//Display necessary information (duration, wav header etc)
		displayWAVheader("test.wav");

		//Calculate fast dBs
		displayBar("test.wav");
		//Send fast dBs to web (php program on www.cc.puv.fi)
		break;	//For testing, just run the loop once
	}
}
