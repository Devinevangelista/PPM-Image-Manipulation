# Devin Evangelista CPSC 1010 Devange
# Section 5 PA4 12.6.2022

PA4: defs.h mainDriver.c getHeader.c writeHeader.c writePixels.c initInputImageArray.c manip.c
		gcc -Wall -o PA4 mainDriver.c getHeader.c writeHeader.c writePixels.c initInputImageArray.c manip.c

run: PA4
		./PA4 Disney.pnm ClemsonPaw.pnm

clean:
		rm PA4
		rm -f output.txt
	
