/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
	
	int notc = 0;                        /* Number of test cases */
	int caseNumber = 1;
	char output[100] = {};
	
	printf("Enter number of cases:");  //Console message
	
	scanf("%d", &notc);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	while(notc >0){
		
		scanf("%[^\n]", output);
		getchar();               //clear new line from input buffer
		
		printf("Case #%d: %s\n",caseNumber, output);	//Print the output of the respective case
		caseNumber++;				//Increase case number
		notc--;				//decrease
	}

}

