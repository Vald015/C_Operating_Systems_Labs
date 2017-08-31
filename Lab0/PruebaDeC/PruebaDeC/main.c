/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    int num = 0;             //Number of words to decipher
    char name[100] ={} ;
    
    printf("Enter number of words to decipher:");  //Console message
    
    //scanf("%d", &num);       //Get number of words to decipher
    
    printf("%d", num);        //Test
    
    printf("Enter the name : ");
    
    scanf("%[^\n]",name);
    
    printf ("Name of Student : %s \n",name);
    
}
