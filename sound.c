#include "sound.h"
#include <stdio.h>

//function definition of displayWAVheader()
void displayWAVheader(char filename[]){
	WAVHeader myhdr;	//an instance of defined struct
	FILE *fp;
	short int samples[SAMPLERATE];
	WAVHeader myhdr;
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1,fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	for(i=0; i<80; i++){
	}
}
void displayWAVheader(char filename[]){
	WAVheader myhdr;
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp ==NULL){
	printf("ERROR of opening file!\n");
	return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("subchunk 1 size: %d\n",myhdr.subchunk1Size);
	printf("audio format: %d\n",myhdr.audioFormat);
	printf("number of channels: %d\n",myhdr.numChannels);
	printf("sample rate: %d\n",myhdr.sampleRate);
	printf("byte rate: %d\n",myhdr.byteRate);
	printf("block align: %d\n",myhdr.blockAlign);
	printf("bits per sample: %d\n",myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("subchunk 2 size: %d\n",myhdr.subchunk2Size);
}
void printID(char id[]){
	int i;
	for(i=0;i<4;i++)
	printf("%c",id[i]);

	printf("\n");
}
