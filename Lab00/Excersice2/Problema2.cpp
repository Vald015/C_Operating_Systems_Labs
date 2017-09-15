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
#include <ctype.h>

#define ROWS 50       /* Set the number of rows */
#define COLUMNS 50    /* Set the number of columns */
#define K 20          /* Set number of rows in the number of words to find */

int checkCase(int a[2], char b[50], int x, int y);  /* Check different cases */

int rows = 0;       /* Number of rows entered by the user */
int columns = 0;    /* Number of columns entered by the user */
char game[ROWS][COLUMNS] = {};    /* Initialize game array */

char words[20][50] = {};    /* Word to search in the game grid */

int main(){

  int notc = 0;       /* Number of test cases */
  int rowIndex = 0;   /* Row index */
  //int cases[8][2] = {{-1,-1}};  /* array for the 8 different cases */
  int cases[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};  /* array for the 8 different cases */
  //char words[20][50] = {};    /* Word to search in the game grid */
  int found = 0;      /* found variable 1 when the word is found, 0 when not */
  int now = 0;          /* number of words */

  scanf("%d",&notc);
  printf("\n");
  getchar();
  //printf("%d\n",notc);/TEST
  while (notc != 0){


  //memset(game, '\0', sizeof(game) * ROWS * COLUMNS);		/* clear previous game */
  for(int h = 0; h< ROWS; h++){
    for(int o = 0; o< columns;o++){
      game[h][o] = '\0';
    }
  }
  for(int h = 0; h< 20; h++){
    for(int o = 0; o< columns;o++){
      words[h][o] = '\0';
    }
  }

  //memset(words, '\0', sizeof(words) * 20 * COLUMNS);		/* clear previous game */

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
  rowIndex = 0;
  //printf("***Enter now!!!!\n");  //TEST

  /* Get number of words to search */
  scanf("%d",&now);
  getchar();
  //printf("%d", now);      //TEST
  /* Get words to search */
  while(rowIndex != now){
    scanf("%50s",words[rowIndex]);
    getchar();      /* Clear input buffer */
    rowIndex++;
    //printf("%s",words[0]);    //TEST
  }
  rowIndex = 0;
  /* Search for the first letter */
  for(int u =0; u < now;u++){
    for(int i = 0;i<rows;i++){
      for(int j = 0;j< columns;j++){
        /* Found first letter */
        if(toupper(words[u][0]) == toupper(game[j][i])){
          //printf("found it: %d // %d\n",i+1,j+1);   //TEST
          /* Check each of the cases */
          for(int q = 0 ; q<8 ; q++){
            found = checkCase(cases[q],words[u],j,i);
            if(found){
              //printf("FOUND IT\n");   //TEST
              printf("%d %d\n", j+1,i+1);     //Print first letter location
              j = columns;     /* End column search */
              i = rows;        /* End row search */
              q = 8;           /* End cases search */
            }
          }
        }
      }
    }
  }
  //rowIndex = 0;      /* Reset row index */
  rows = 0;
  columns = 0;
  now = 0;
  notc--;
  //printf("new");    //TEST
  }   //NOTC
  //printf("%s\n",game[rowIndex]);    /* TEST */
  return 0;
}
/* Checks a given case of a word to be found */
int checkCase(int a[2], char b[50],int x, int y){
  int k = 0;    /* k is the lenght of the word to be found */
  int ro = x;
  int co = y;
  for(; b[k] != '\0'; ++k);   /* count characters until null value */
  //printf("k = %d\n", k);    //TEST
  //printf("case = %d %d\n", a[0],a[1]);    //TEST
  /* Check if the word is whithin the bounds of the array with the given case */
  if(((x+a[0]*(k-1)) < 0) || ((x+a[0]*(k-1)) > rows) || ((y+a[1]*(k-1)) < 0) || ((y+a[1]*(k-1)) > columns)){
    return 0;
  }else{
    /* Check if all the characters of the word to be found match */
    for(int l = 0;l <= k-1; l++){
      if(toupper(game[ro][co]) == toupper(b[l])){
        ro = ro + a[0];   /* x + case */
        //printf("%d ", ro);      //TEST
        co = co + a[1];   /* y + case */
        //printf("%d\n", co);     //TEST
      }else{
        return 0;
      }
    }
    return 1;
  }
}
