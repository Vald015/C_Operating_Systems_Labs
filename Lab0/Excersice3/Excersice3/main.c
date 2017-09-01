/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define size 25

int main(){
	
	int notc = 0;                        /* Number of test cases */
	int caseNumber = 1;
	char input[size] = {};
	char temp[size] = {};
	char output[size] = {};
	int i = 0, k = 0,j = 0;
	
	printf("Enter number of cases:\n");  //Console message
	
	scanf("%d", &notc);          //Get number of words to decipher
	getchar();                  //clear new line from input buffer
	
	//printf("%d \n", notc);			//TEST
	while(notc > 0){
		
		scanf("%[^\n]", input);		
		getchar();					//clear new line from input buffer
	
		//printf("%s\n",input);	//TEST
		
		memset(temp, '\0', sizeof(temp));		/* Clear Deciphered array */
		memset(output, '\0', sizeof(output));		/* Clear Deciphered array */
		
		i = strlen(input);
	
		while(i > 0){
			i--;
			temp[k] = input[i];
			k++;
		}
		
		printf("%s\n",temp);
		
		temp[k] = '\0';
		
		for(i = 0; temp[i] != '\0'; i++){
			if(temp[i+1] == '\0' || temp[i+1] == ' '){
				for(k = i; temp[k] != ' ' && k>=0; k = k - 1){
					output[j] = temp[k];
					j++;
				}
				//j++;
				output[j] = ' ';
				j++;
				i = i+1;
			}
		}
		
		j--;
		//output[j] = '\0';
		printf("Case #%d: %s\n", caseNumber , output);
		caseNumber++;
		notc--;
		k = 0;
		j = 0;
	}
}
