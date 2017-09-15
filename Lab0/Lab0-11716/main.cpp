/* 	Author: Osvaldo A. Ramirez
 ICOM5007- Lab0 Ex. 11716
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    //int numOfWords;             //Number of words to decipher
    //int currentWord = 0;        //current word index for str array
    char name[100];
    //int i = 0;
    //char ch;
    
    
    //char str[][numOfWords];
    //scanf("%s", &str);
    //printf("Enter number of words to decipher\n");  //Console message
    
    //scanf("%d", &numOfWords);       //Get number of words to decipher
    //printf("%d", numOfWords);        //Test
    
    //char str[10000][numOfWords];        //Initialize array with number of words to decipher
    
    //printf("\n");            //new line
    printf("\nEnter the name : ");
    scanf("% [^\n] s",name);
    printf ("\nName of Student : %s ",name);
    
    //while(ch != '\n'){
    //    ch = getchar();
    //    str[0][i] = ch;
    //    i++;
    //}
    //str[0][i] = '\0';
    //printf("%s", str[currentWord]);         //Test
    
    
    
    //scanf("%[^\n]s",&str[currentWord]);
    //fgets(str[currentWord],10000,stdin);
    //printf("%s", str[currentWord]);         //Test
    
    
    
    //while(currentWord != numOfWords){
        //fgets(str[currentWord],10000,stdin);
        //scanf("%10[0-9a-zA-Z ]", str);
        //scanf("%[^\n]s",&str[currentWord]);
        //scanf("%[^ ]s",&str[currentWord]);
        //scanf("%s", &str[currentWord]);         //Get word to decipher
    //    currentWord++;              //Increment current Word counter
        //printf("\n");               //new line
        
    //}
    
    //currentWord = 0;            //Reset current Word counter

    //printf("Length of string a = %d \n", strlen(str[0]));
    
    //int size = sizeof(str);
    //printf("%d",size);
    //printf("\n");               //new line
    
    //while(currentWord != numOfWords){
        
    //    scanf("%s", &str[currentWord]);         //Get word to decipher
    //    printf("%s", str[currentWord]);         //Test
    //    currentWord++;
    //    printf("\n");            //new line
        
    //}
    //scanf("%s", &str[currentWord]);         //Get word to decipher
    //printf("%s", str[currentWord]);         //Test
    
    //printf("Termino");            //new line
    
    //currentWord++;              //Increment current word index
    //scanf("%s", &str[currentWord]);
    //printf("%s", str[currentWord]);
    
    //printf("\n");            //new line
    
    return 0;
}
