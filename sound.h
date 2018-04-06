//#define DEBUG
//Constant definition
#define SAMPLERATE 16000
//Header file for processing sound (WAV) file
//Define the wav header
typedef struct{
	char chunkID[4];
	unsigned int chunkSize;	//4 bytes
	char format[4];	//"WAVE"
	char subchunk1ID[4];	//"fmt"
	unsigned int subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];	//"data"
	unsigned int subchunk2Size;
}WAVHeader;

//Function prototypes
void displayWAVheader(char filename[]);
void displayBar(char filename[]);
void printID(char []);

