/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
	
	int ntd = 0;                        /* Number of words to decipher */
	
	printf("Enter number of words to decipher:");  //Console message
	
	scanf("%d", &ntd);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	while(ntd >0){
		//scanf("%[^\n]",wordToDecipher);
		//getchar();               //clear new line from input buffer
		
		//wordDeciphered = {};			/* Clear Deciphered array */
		//memset(wordDeciphered, '\0', sizeof(wordDeciphered));		/* Clear Deciphered array */
		
		//printf ("%s",wordDeciphered);
		
		puts("INVALID");
		ntd--;
	}

}

