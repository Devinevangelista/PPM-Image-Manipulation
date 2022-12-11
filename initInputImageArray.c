/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#include "defs.h"
//Fill the array function
void fillImageArray(pixel P_array[], int P_width, int P_height, FILE *RGBvalue){
	int i = 0;

	for (i = 0; i < P_height*P_width; i++ ) {
			
			fscanf(RGBvalue, " %u", &P_array[i].r);
			fscanf(RGBvalue, " %u", &P_array[i].g);
			fscanf(RGBvalue, " %u", &P_array[i].b);


	}
}
