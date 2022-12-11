/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 Lab PA4
*/

#include "defs.h"
//Write pixels to stdout function

void reduceSize(pixel P_array3[], int P_width3, int P_height3, pixel reduceSizeArr[]){
	int i;
	int j = 0;
	for (i = 0; i < (P_width3*P_height3); i+=2) {
		
		if(i+P_width3+1 != (P_height3 * P_width3) -1){
			//updates the halfsizeimagearray			
			reduceSizeArr[j].r = P_array3[i].r;
			reduceSizeArr[j].g = P_array3[i].g;
			reduceSizeArr[j].b = P_array3[i].b;
			j++;
		}

		if (((i/P_width3)%2) != 0){
			i+=P_width3;
		}
	}
}

//greenscreen function
void greenScreen(pixel normalImage[], pixel gsImage[], pixel newImage[], int imgWidth, int imgHeight){
	int i;
	for (i = 0; i < (imgWidth*imgHeight); i++){
		// IF green screen image = green pixel, then print from the other image
		if (gsImage[i].r == 0 && gsImage[i].g == 255 && gsImage[i].b == 0){  
			
			newImage[i].r = normalImage[i].r;
			newImage[i].g = normalImage[i].g;
			newImage[i].b = normalImage[i].b;
		}

		else {
			newImage[i].r = gsImage[i].r;
			newImage[i].g = gsImage[i].g;
			newImage[i].b = gsImage[i].b;

		}
	}

}

