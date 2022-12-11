/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <stdlib.h>
	typedef struct header{ // structures declared
		char type[3];
		int width;
		int height;
		int maxColor;
	}header;

	typedef struct pixel{
		unsigned int r;
		unsigned int g;
		unsigned int b;
	}pixel;
	
// prototypes
	header getHeader(FILE*);
	void writeHeader(header, FILE*);
	void fillImageArray(pixel[], int, int, FILE*);
	void writePixels(pixel[], int, int, FILE*);
	void reduceSize(pixel[], int, int, pixel[]);
	void greenScreen(pixel[], pixel[], pixel[], int, int);
	int showMenu();
#endif
	
