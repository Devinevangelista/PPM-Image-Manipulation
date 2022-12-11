/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#include "defs.h"
//Write pixels to stdout function
void writePixels(pixel P_array2[], int P_width2, int P_height2, FILE *outPut){
	int i;
	for (i = 0; i < P_width2*P_height2; i++) {
	//	print each value from array to stdout
		fprintf(outPut, "%i %i %i\n",  P_array2[i].r, P_array2[i].g, P_array2[i].b);
	}
}



