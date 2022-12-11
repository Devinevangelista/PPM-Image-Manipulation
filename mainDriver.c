/* 
Devin Evangelista
Devange
12.7.2022
CPSC 101 Section 5 
Fall 2022 PA4
*/

#include "defs.h"

int showMenu(){
	
	int userchoice;
	printf("Image Manipulation Program\n");
	printf("1. reduce size of image #1\n");
	printf("2. superimpose image #2 onto image #1\n");
	printf("3. reduce size of superimposed image\n");
	printf("4. quit the program\n");
	scanf("%i", &userchoice);
	return userchoice;
}

int main ( int argc, char *argv[]){
	
	int userchoice;

	FILE *inputPointer = fopen(argv[1], "r");
	FILE *inputPointerGS = fopen(argv[2], "r");
	
	header ActualHeader = getHeader(inputPointer);
	header Halfsizeheader;
	//header for greenScreen
	header gsHeader = getHeader(inputPointerGS);

//	header Halfsizeheader;

	//declare Array sizes from images
	int imageArraySize = ActualHeader.height * ActualHeader.width;
	int greenScreenSize = gsHeader.height * gsHeader.width;
	
	//half the header width & height and assign halfSizearr size
	Halfsizeheader.width = ActualHeader.width/2;
	Halfsizeheader.height = ActualHeader.height/2;
	Halfsizeheader.maxColor = 255;
	int HalfsizeArea = Halfsizeheader.width*Halfsizeheader.height;

	//Declare pixel vars
	pixel *halfSizeArr;
	pixel *image1;
	pixel *image2;
	pixel *newImageArr;
	pixel *halfSuperimposedIN;
	pixel *halfSuperimposedOUT;

	
	//allocate memory for both images for original fill image arr
	image1 = (pixel *)calloc(imageArraySize, sizeof(pixel)); 
	image2 = (pixel *)calloc(greenScreenSize, sizeof(pixel));
	
	fillImageArray(image1, ActualHeader.width, ActualHeader.height, inputPointer);
	fillImageArray(image2, gsHeader.width, gsHeader.height, inputPointerGS);
	
	int choice2Counter = 0;
	int choice1Counter = 0;
	int choice3Counter = 0;

	while(userchoice != 4) {
	
	userchoice = showMenu();

		switch(userchoice) {
			
			case 1:
				
				if(choice1Counter == 0){
					
					halfSizeArr = (pixel *)calloc(HalfsizeArea, sizeof(pixel));

					reduceSize(image1, ActualHeader.width, ActualHeader.height, halfSizeArr);

					//File pointer for smaller image output
					FILE *outputPointer = fopen("smallerImage1.pnm", "w");

					//write Header and pixels
					writeHeader(Halfsizeheader, outputPointer);
					writePixels(halfSizeArr, Halfsizeheader.width, Halfsizeheader.height, outputPointer);
					choice1Counter = 1;

				}
				// if menu choice one has been chosen already, send this
				else{
					printf("Menu 1 option already chosen.\n");
				}

				break;

			case 2:
				
				if(choice2Counter == 0){

					newImageArr = (pixel *)calloc(imageArraySize, sizeof(pixel));
					
					greenScreen(image1, image2, newImageArr, ActualHeader.width, ActualHeader.height);
					//File pointer for smaller image output
					FILE *outputPointer2 = fopen("greenScreen1.pnm", "w");

					//write Header and pixels
					writeHeader(gsHeader, outputPointer2);
					writePixels(newImageArr, ActualHeader.width, ActualHeader.height, outputPointer2);
					choice2Counter = 1;

				} 
				// if menu choice two has been chosen already, send this
				else {
					printf("Menu 2 option already chosen.\n");
					}

				break;
			
			case 3:
				
					if(choice3Counter == 0){
					halfSuperimposedIN = (pixel *)calloc(imageArraySize, sizeof(pixel));
					halfSuperimposedOUT = (pixel *)calloc(imageArraySize, sizeof(pixel));

					greenScreen(image1, image2, halfSuperimposedIN, ActualHeader.width, ActualHeader.height);
					FILE *outputPointer3 = fopen("smallerImage2.pnm", "w");
				
					reduceSize(halfSuperimposedIN, ActualHeader.width, ActualHeader.height, halfSuperimposedOUT);
					writeHeader(Halfsizeheader, outputPointer3);
					writePixels(halfSuperimposedOUT, Halfsizeheader.width, Halfsizeheader.height, outputPointer3);
					choice3Counter = 1;
				}
				//if menu choice three has been chosen, send this
				else {
					printf("Menu 3 option already chosen.\n");
				}

				break;

			case 4:
				//end switch
				break;
			}	
		
		}
	

	return 0;
}
