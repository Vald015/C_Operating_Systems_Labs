/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb00 - Excersice 2: Where's Waldorf
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 50       /* Set the number of rows */
#define COLUMNS 50    /* Set the number of columns */
#define K 20          /* Set number of rows in the number of words to find */

int checkCase(int a[2], char b[50], int x, int y);  /* Check different cases */

int rows = 0;       /* Number of rows entered by the user */
int columns = 0;    /* Number of columns entered by the user */
char game[ROWS][COLUMNS] = {};    /* Initialize game array */

char words[20][50] = {};    /* Word to search in the game grid */
int now = 0;


int main(){

  int notc = 0;       /* Number of test cases */
  int rowIndex = 0;   /* Row index */
  //int cases[8][2] = {{-1,-1}};  /* array for the 8 different cases */
  int cases[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};  /* array for the 8 different cases */
  char words[20][50] = {};    /* Word to search in the game grid */
  int found = 0;      /* found variable 1 when the word is found, 0 when not */

  /*scanf("%d",&notc);
  getchar();
  printf("%d\n",notc);
  */

  scanf("%d %d", &rows, &columns);    /* Get the values of rows and columns from the user */
  getchar();            /* Clear input buffer */
  //printf("%d %d",rows, columns);

  /* Fill the game grid array with the characters */
  while(rowIndex != rows){
    scanf("%50s", game[rowIndex]);    /* Enter row by row */
    getchar();    /* Clear input buffer */
    //printf("%s", game[rowIndex]);   //Test
    rowIndex++;     /* Increase row index variable */
  }
  printf("***done!!!!\n");
  /* Get word to search */
  scanf("%50s",words[0]);
  getchar();      /* Clear input buffer */
  //printf("%s",words[0]);

  /* Search for the first letter */
  for(int i = 0;i<rows;i++){
    for(int j = 0;j< columns;j++){
      /* Found first letter */
      if(words[0][0] == game[i][j]){
        printf("found it: %d // %d\n",i,j);
        /* Check each of the cases */
        for(int q = 0 ; q<8 ; q++){
          found = checkCase(cases[q],words[0],i,j);
          if(found){
            j = columns;
            i = rows;
            q = 8;
            printf("FOUND IT");
          }
        }
      }
    }
  }
  rowIndex = 0;      /* Reset row index */
  //printf("%s\n",game[rowIndex]);    /* TEST */
  return 0;
}
/* Checks a given case of a word to be found */
int checkCase(int a[2], char b[50],int x, int y){
  int k = 0;    /* k is the lenght of the word to be found */
  int ro = x;
  int co = y;
  for(; b[k] != '\0'; ++k);   /* count characters until null value */
  printf("k = %d\n", k);    //TEST
  printf("case = %d %d\n", a[0],a[1]);
  /* Check if the word is whithin the bounds of the array with the given case */
  if(((x+a[0]*(k-1)) < 0) || ((x+a[0]*(k-1)) > rows) || ((y+a[1]*(k-1)) < 0) || ((y+a[1]*(k-1)) > columns)){
    return 0;
  }else{
    /* Check if all the characters of the word to be found match */
    for(int l = 0;l <= k; l++){
      if(game[ro][co] == b[l]){
        ro = ro + a[0];   /* x + case */
        printf("%d ", ro);
        co = co + a[1];   /* y + case */
        printf("%d\n", co);
      }else{
        return 0;
      }
    }
    return 1;
  }
}
