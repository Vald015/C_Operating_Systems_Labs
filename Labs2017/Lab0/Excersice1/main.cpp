/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 10055
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    unsigned long num1;	    /* first number */
    unsigned long num2;	    /* Second number */
    unsigned long total;	/* Difference */
    
    printf("Please enter numbers separated by space:");
    printf("\n");	        //new line
    
    /*  While there is a new number keep getting difference. Since we are using unsigned
        long we need to make sure that num1 & num2 are never negative. While loop is repited
        as long as there are two inputs of the same type (Set by the ==2 in the while) */
    while(scanf("%lu %lu", &num1, &num2) == 2){
        
        if(num1 >= num2){
            
            total = num1 - num2;	// Difference
            
        }else{
            
            total = num2 - num1;	//Difference
            
        }
        printf("\n");       //new line
        printf("%lu", total);	    //Print total
    }
    //printf("\n\n");
    return 0;
}
