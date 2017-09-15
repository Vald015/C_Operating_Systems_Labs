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

int checkWords(int a[2], char b[50], int x, int y);  /* Check different cases */

int rows = 0;       /* Number of rows entered by the user */
int columns = 0;    /* Number of columns entered by the user */
char game[ROWS][COLUMNS] = {};    /* Initialize game array */
int cases[8][2] = {{-1,-1}};  /* array for the 8 different cases */
char words[20][50] = {};    /* Word to search in the game grid */


int main(){

  int notc = 0;       /* Number of test cases */
  int rowIndex = 0;   /* Row index */
  int cases[8][2] = {{-1,-1}};  /* array for the 8 different cases */
  char words[20][50] = {};    /* Word to search in the game grid */
  int found = 0;

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

  /* Get word to search */
  scanf("%50s",words[0]);
  getchar();      /* Clear input buffer */
  //printf("%s",words[0]);

  /* Search for the first letter */
  for(int i = 0;i<rows;i++){
    for(int j = 0;j< columns;j++){
      if(words[0][0] == game[i][j]){
        printf("found it: %d // %d\n",i,j);
        found = checkWords(cases[0],words[0],i,j);
        if(found){
          j = columns;
          i = rows;
          printf("FOUND IT");
        }
      }
    }
  }
  rowIndex = 0;      /* Reset row index */
  //printf("%s\n",game[rowIndex]);    /* TEST */

  return 0;
}

int checkWords(int a[2], char b[50],int x, int y){
  int k = 0;
  for(; b[k] != '\0'; ++k);
  printf("%d\n", k);
  if(((x+a[0]*(k-1)) < 0) || ((x+a[0]*(k-1)) > rows) || ((y+a[1]*(k-1)) < 0) || ((y+a[1]*(k-1)) > columns)){
    /*int test1 = (x+a[0]*(k));
    printf("%d\n",test1);*/
    return 0;
  }else{
    for(int l = 0;l <= k; l++){
      if(game[x][y] == b[l]){
        x = x + a[0];
        printf("%d", x);
        y = y + a[1];
        printf("%d",y);
      }else{
        return 0;
      }
    }
    return 1;
  }
}
