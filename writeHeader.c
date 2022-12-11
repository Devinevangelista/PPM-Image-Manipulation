/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#include "defs.h"
//Header Function
void writeHeader(header input, FILE*headOutput){
	
	fprintf(headOutput, "P3\n");
	fprintf(headOutput, "%d %d %d\n", input.width, input.height, input.maxColor);
}

