/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 100

int main(){
	
	int notc = 0;                        /* Number of test cases */
	int caseNumber = 1;
	char input[size] = {};
	char output[size] = {};
	char temp[size] = {};
	int i;
	int k =0;
	
	printf("Enter number of cases:");  //Console message
	
	scanf("%d", &notc);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	while(notc >0){
		
		scanf("%[^\n]", input);
		getchar();               //clear new line from input buffer
		
		i = sizeof(input);
		
		
		while(i != 0){
			if(input[i] != ' '){
				temp[k] = input[i];
			}
			//for(j = 0;)
			i--;
		}
		
		printf("Case #%d: %s\n",caseNumber, output);	//Print the output of the respective case
		caseNumber++;				//Increase case number
		notc--;				//decrease
	}

}

