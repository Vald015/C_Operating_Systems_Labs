/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716 uva.onlinejudge.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMOFCHAR 10001				/* Contant maximum number of characters 10000 + null value */

int main(){
	
	int ntd = 0;                        /* Number of words to decipher */
	char wordToDecipher[NUMOFCHAR] ={} ;	/* Array that contains word to be deciphered */
	char wordDeciphered[NUMOFCHAR] = {};	/* Array that contains word deciphered */
	
	printf("Enter number of words to decipher:");  //Console message
	
	scanf("%d", &ntd);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	while(ntd >0){
		scanf("%[^\n]",wordToDecipher);		//Get word to decipher
		getchar();               //clear new line from input buffer
		
		int length = strlen(wordToDecipher);		/* Length of the given array */
		int root = sqrt(length);					/* Root of the length of the array */
		
		memset(wordDeciphered, '\0', sizeof(wordDeciphered));		/* Clear Deciphered array */
		
		
		if(root * root == length){		/* Check if its a perfect square */
			int current = 0;			/* Current index of the wordDeciphered characters */
			for(int i =0; i < root; i++){
				for(int j = i; j < length; j = j + root){		//j + root to decipher word
					/* set character indexed on word deciphered to character deciphered in Word to decipher */
					wordDeciphered[current++] = wordToDecipher[j];
				}
			}
			printf ("%s \n",wordDeciphered);			//Print word deciphered
		}else{
			puts("INVALID");						//Invalid if the word length is not a perfect square
		}
		ntd--;				//Decrease number of words to decipher
	}
}
