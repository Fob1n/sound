#include "screen.h"
#include "sound.h"
#include <stdio.h>
#include <math.h>

//Function definition of displayBar()
/*This function opens the "test.wav" file and read the second part (data)
of the file, and they should be in S16_LE format, and there should be
16000 of them. The function processes every 200 samples and calculate
their RAM value and renders this value as a vertical bar on the
terminal screen*/
void displayBar(char filename[]){
	FILE *fp;
	short int samples[SAMPLERATE];
	double dB, sum_200, rms_80[80];
	int i, j;
	WAVHeader myhdr;	//Dummy header to skip over reading from file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	/*All the samples of 1 sec are read to the array samples, we need
	to run a loop 80 times for 80 bars, and each loop will calculate
	a RMS value of 200 samples*/
	for(i=0; i<80; i++){
		for(j=0, sum_200=0.0; j<200; j++){
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] = sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);		//In order to display sound value in a screen, we need to use decibel
#ifdef DEBUG
		printf("RMS[%d] = %10.4f = %10.4fdB\n", i, rms_80[i], dB);
#else
		bar(i,dB);
#endif
	}	//For
}	//Function
//Function definition of displayWAVheader()
void displayWAVheader(char filename[]){
	WAVHeader myhdr;	//An instance of defined struct
	FILE *fp;
	fp = fopen(filename, "r");	//Open the file for reading
	if(fp == NULL){	//If fopen is failed
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	gotoxy(0, 0);
	setColor(47);setColor(BLACK);
	printf(" %s  ", filename);
	setColor(42);setColor(BLACK);
	printf(" Channel= %d  ",myhdr.numChannels);
	setColor(46);setColor(BLACK);
	printf(" S.R.= %d Hz  ",myhdr.sampleRate);
	setColor(45);setColor(BLACK);
	printf(" Duration= %ds  ", myhdr.subchunk2Size/myhdr.byteRate);
	setColor(40);setColor(WHITE);
/*	printID(myhdr.chunkID);
	printf("Chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("Subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("Audio Format :%d\n", myhdr.audioFormat);
	printf("Number of Channels: %d\n", myhdr.numChannels);
	printf("Sample Rate: %d\n", myhdr.sampleRate);
	printf("Byte Rate: %d\n", myhdr.byteRate);
	printf("Block Align: %d\n", myhdr.blockAlign);
	printf("Bits per Sample: %d\n", myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("Subchunk 2 size: %d\n", myhdr.subchunk2Size);
*/}

void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);
	printf("\n");
}
