/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 3 Code Jam Reverse Words
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 100

int main(){
	
	int notc = 0;							/* Number of test cases */
	int caseNumber = 1;						/* Current case number */
	char input[size] = {};					/* Array to store the input */
	char temp[size] = {};					/* Temporary array to revert the whole string */
	char output[size] = {};					/* Output array */
	int i = 0, k = 0,j = 0;					/* array indexes */
	
	printf("Enter number of cases:\n");  //Console message
	
	scanf("%d", &notc);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	//printf("%d \n", notc);			//TEST
	while(notc > 0){
		
		scanf("%[^\n]", input);		//Get input
		getchar();					//clear new line from input buffer
	
		//printf("%s\n",input);	//TEST
		
		memset(temp, '\0', sizeof(temp));		/* Clear Deciphered array */
		memset(output, '\0', sizeof(output));		/* Clear Deciphered array */
		
		i = strlen(input);					/* Get array length */
		
		//Invert the whole string
		while(i > 0){
			i--;					//Decrease input index
			temp[k] = input[i];	//Ex. Set the first position of temp equal to the last position of input
			k++;					//Increase temp index
		}
		
		//printf("%s\n",temp);			//Test
		
		/* Invert the words */
		for(i = 0; temp[i] != '\0'; i++){		//Increase i until the end of the array
			if(temp[i+1] == '\0' || temp[i+1] == ' '){//if next character in the array is a space or null
				/* invert the word until value of k is negative or a space is found */
				for(k = i; temp[k] != ' ' && k>=0; k = k - 1){
					output[j] = temp[k];
					j++;				//Increase output index
				}
				//j++;
				output[j] = ' ';		//Add space to output
				j++;					//Increase output index
				i = i+1;				//Increase i since a space was added
			}
		}
		
		/* When null is found */
		//j--;			//
		//output[j] = '\0';
		printf("Case #%d: %s\n", caseNumber , output);		//Print the case and output of the test case
		caseNumber++;			//Increase Case number counter
		notc--;					//Decrease number of cases
		k = 0;					//Reset index k
		j = 0;					//Reset index j
	}
}
