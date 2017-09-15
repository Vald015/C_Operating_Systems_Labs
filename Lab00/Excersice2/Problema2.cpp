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

bool checkWords(int case[2]);  /* Check different cases */

int main(){

  int notc = 0;       /* Number of test cases */
  int rowIndex = 0;   /* Row index */
  int rows = 0;       /* Number of rows entered by the user */
  int columns = 0;    /* Number of columns entered by the user */
  int cases[8][2] = {{-1,-1}};
  char words[20][50] = {};

  /*scanf("%d",&notc);
  getchar();
  printf("%d\n",notc);
  */

  scanf("%d %d", &rows, &columns);    /* Get the values of rows and columns from the user */
  getchar();            /* Clear input buffer */
  //printf("%d %d",rows, columns);
  char game[ROWS][COLUMNS] = {};    /* Initialize game array */

  /* Fill the game grid array with the characters */
  while(rowIndex != rows){
    scanf("%s\n", game[rowIndex]);    /* Enter row by row */
    getchar();    /* Clear input buffer */
    //printf("%s", game[rowIndex]);   //Test
    rowIndex++;     /* Increase row index variable */
  }
  
  scanf("%s\n",words[0]);
  getchar();
  printf("%s",words[0]);

  /*for(int i = 0;i<rows;i++){
    for(int j = 0;j< columns,j++){

    }
  }*/
  rowIndex = 0;       /* TEST*/
  printf("%s\n",game[rowIndex]);    /* TEST */

  return 0;

}
