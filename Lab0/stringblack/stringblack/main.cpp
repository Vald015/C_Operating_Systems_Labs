/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMOFCHAR 10001

int main(){
	
    int ntd = 0;                        /* Number of words to decipher */
    char wordToDecipher[NUMOFCHAR] ={} ;	/* Array that contains word to be deciphered */
	char wordDeciphered[NUMOFCHAR] = {};	/* Array that contains word deciphered */
    
    printf("Enter number of words to decipher:");  //Console message
    
	scanf("%d", &ntd);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
    
    //REMOVE ME
	//printf("%d",ntd);
	
	
	while(ntd >0){
		scanf("%[^\n]",wordToDecipher);
		getchar();               //clear new line from input buffer
	
		int length = strlen(wordToDecipher);		/* Length of the given array */
		int root = sqrt(length);
	
		//wordDeciphered = {};			/* Clear Deciphered array */
		memset(wordDeciphered, '\0', sizeof(wordDeciphered));		/* Clear Deciphered array */
		
		
		if(root * root == length){		/* Check if its a perfect square */
			//TODO Decipher
			//puts("A lo loco");
			int current = 0;
			for(int i =0; i < root; i++){
				for(int j = i; j < length; j = j + root){
					wordDeciphered[current++] = wordToDecipher[j];
				}
			}
			printf ("%s",wordDeciphered);
		}else{
			puts("INVALID");
		}
		ntd--;
	}
	
    //printf ("%s",wordToDecipher);

}

