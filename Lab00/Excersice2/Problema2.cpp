/*	Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb00 - Excersice 2: Where's Waldorf
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int notc = 0;
  int rows = 0;
  int columns = 0;
  int rowIndex = 0;

  /*scanf("%d",&notc);
  getchar();
  printf("%d\n",notc);
  */

  scanf("%d %d", &rows, &columns);
  getchar();
  //printf("%d %d",rows, columns);
  //TODO check this shit
  char game[rows][columns];

  while(rowIndex != rows){
    scanf("%s", game[rowIndex]);
    getchar();
    //printf("%s", game[rowIndex]);
    rowIndex++;
  }

  rowIndex = 0;

  while(rowIndex != rows){
    printf("%s\n",game[rowIndex]);
    rowIndex++;
  }

  return 0;

}
