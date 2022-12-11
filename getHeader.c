/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#include "defs.h"

struct header getHeader(FILE * disneyHeader){
	
	header NewHeader;

	fscanf(disneyHeader," %s", NewHeader.type);

	fscanf(disneyHeader," %d", &NewHeader.width);

	fscanf(disneyHeader, " %d", &NewHeader.height);

	fscanf(disneyHeader, " %d", &NewHeader.maxColor);

	return NewHeader;
}

