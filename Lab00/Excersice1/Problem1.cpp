/*	Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb00 - Excersice 1: Tic-Tac-Toe-Tomek 10010
 * 	uva.onlinejudge.org
 */

#include <iostream>
#include <stdio.h>
//#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Constants */
#define P1 X		/* Player 1 symbol */
#define P2 Y		/* Player 2 Symbol */
#define EMPTY .	/* Empty space */
#define ANY T		/* Player 1 or Player 2 symbol */
/* String constants */
#define XWON "Player X Won\n"				/* Player 1 won string */
#define YWON "Player Y Won\n"				/* Player 2 won string  */
#define DRAW "Draw Game\n"				/* Tie game string */
#define GNC "Game has not completed\n"	/* Incomplete game string */
#define GO "Game Over\n"		/* Game over string */

#define ROWS 4		/* number of rows of the game board */
#define COLUMNS 4	/* number of columns of the game board */
//#define PLAYS 16	/* number of plays including T */

/*
 *  input Example:	XXXO
										OXTX
										OOOO
										XXX.
 */

int main() {

	int notc = 0;			      /* number of test cases */
	int rowIndex = 0;       /* Row index for getting the input to the right place */
	int columnIndex = 0;		/*  */
	int caseNumber = 1;			/* Case number counter */
  int result = 0;					/* Records the result for the current case */

	char game[ROWS][COLUMNS] = {};	/* Game two dimensional array (first array is the rows, second array is the  columns) */
	/*
	printf("Enter notc: \n");
	scanf("%d", &notc);
	getchar();
	printf("notc = %d\n",notc);
	*/
  //while(notc > 0){
	/* Goes from 0-3 */
	while(rowIndex != ROWS){
		scanf("%4s",game[rowIndex]);		/* Get string with 4 characters */
		getchar();											/* Clean input buffer */
		//printf("%s\n", game[rowIndex]);		//Test
		rowIndex++;				/* Increase row index */
	}

  /*
   * Check if there are 4X or 4O in a row in rows and colums.
   * It could also be 3X and 1T.
   * Plus: Check if this is an unfinished game.
   */
	 int i = 0;
  for(; i < ROWS; i++){
    if(result == 0){
      if((game[i][0] == 'X'|| game[i][0] == 'T')&&(game[i][1] == 'X'|| game[i][1] == 'T')
        &&(game[i][2] == 'X'|| game[i][2] == 'T')&&(game[i][3] == 'X'|| game[i][3] == 'T')){
          result = 1;
      }else if((game[0][i] == 'X'|| game[0][i] == 'T')&&(game[1][i] == 'X'|| game[1][i] == 'T')
        &&(game[2][i] == 'X'|| game[2][i] == 'T') && (game[3][i] == 'X'|| game[3][i] == 'T')){
          result = 1;
        }else if ((game[i][0] == 'O'|| game[i][0] == 'T') && (game[i][1] == 'O'|| game[i][1] == 'T')
        && (game[i][2] == 'O'|| game[i][2] == 'T') && (game[i][3] == 'O'|| game[i][3] == 'T')){
          result = 2;
      }else if ((game[0][i] == 'O'|| game[0][i] == 'T') && (game[1][i] == 'O'|| game[1][i] == 'T')
        && (game[2][i] == 'O'|| game[2][i] == 'T') && (game[3][i] == 'O'|| game[3][i] == 'T')){
          result = 2;
      }
  }else{
    i = ROWS;
  }
}
  /* Diagonal cases */
  if(result == 0){
    if((game[0][0] == 'X'|| game[0][0] == 'T')&&(game[1][1] == 'X'|| game[1][1] == 'T')
      &&(game[2][2] == 'X'|| game[2][2] == 'T')&&(game[3][3] == 'X'|| game[3][3] == 'T')){
        result = 1;
    }else if((game[0][0] == 'O'|| game[0][0] == 'T')&&(game[1][1] == 'O'|| game[1][1] == 'T')
      &&(game[2][2] == 'O'|| game[2][2] == 'T')&&(game[3][3] == 'O'|| game[3][3] == 'T')){
        result = 2;
    }else if((game[0][3] == 'X'|| game[0][3] == 'T')&&(game[1][2] == 'X'|| game[1][2] == 'T')
      &&(game[2][1] == 'X'|| game[2][1] == 'T')&&(game[3][0] == 'X'|| game[3][0] == 'T')){
        result = 1;
    }else if((game[0][3] == 'O'|| game[0][3] == 'T')&&(game[1][2] == 'O'|| game[1][2] == 'T')
      &&(game[2][1] == 'O'|| game[2][1] == 'T')&&(game[3][0] == 'O'|| game[3][0] == 'T')){
        result = 2;
    }
  }

	i=0;
	/* Check if the game has not ended */
	while(i!=rows){
		if(result ==0){
			if(game[i][0] == '.'|| game[i][1] == '.'|| game[i][2] == '.'|| game[i][3] == '.'){
				result = 3;
			}
		}else{
			i = rows;
		}
	}

	/* Print test case results */
  if(result == 0){
		/* If draw game */
    printf("Case #%d: %s",caseNumber,DRAW);
  }else if(result == 1){
		/* If player 1 won */
    printf("Case #%d: %s", caseNumber, XWON);
  }else if(result == 2){
		/* If Player 2 won */
    printf("Case #%d: %s", caseNumber, YWON);
  }else if(result == 3){
		/* If incomplete game */
    printf("Case #%d: %s", caseNumber,GNC);
  }
  caseNumber++;			/* Increase case number */
	result = 0;				/* Reset reult variable */
	rowIndex = 0;			/* Reset row index */
//} //While notc closing bracket
	return 0;
}
