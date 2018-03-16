#include "sound.h"
#include <stdio.h>

//Function definition of displayBar()
/*This function opens the "test.wav" file and read the second part (data)
of the file, and they should be in S16_LE format, and there should be
16000 of them. The function processes every 200 samples and calculate
their RAM value and renders this value as a vertical bar on the
terminal screen*/
void displayBar(char filename[]){
	FILE fp*;
	short int samples[SAMPLERATE];
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
	for(int i=0; i<80; i++){
		for(int j=0; j<200; j++){
		}
	}
}
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
	printID(myhdr.chunkI D);
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
}

void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);
	printf("\n");
}
