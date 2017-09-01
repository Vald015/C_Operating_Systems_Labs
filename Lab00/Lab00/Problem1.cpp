
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Constants */
#define P1 X		/* Player 1 symbol */
#define P2 Y		/* Player 2 Symbol */
#define EMPTY .			/* Empty space */
/* String constants */
#define XWON "Player X Won\n"				/* Player 1 won string */
#define YWON "Player Y Won\n"				/* Player 2 won string  */
#define Draw "Draw Game\n"				/* Tie game string */
#define GNC "Game  has not completed\n"	/* Incomplete game string */
#define GO "Game Over\n"		/* Game over string */

#define GAMESIZE 4	/* size of the game board */
#define PLAYS 16	/* number of plays including T */

/*	input:	XTXXOXOXOOOXOOXO
 
	input:	XXXO
			OXTX
			OOOO
			XXX.
 */
 


int main() {
	
	int notc = 0;			/* number of test cases */
	int row = 0;
	int column = 0;
	
	char game[4][4] = {};	/* Game two dimensional array (first array is the rows, second array is the  columns) */
	/*
	printf("Enter notc: \n");
	scanf("%d", &notc);
	getchar();
	printf("notc = %d\n",notc);
	*/
	
	scanf("%4s",game[0]);
	getchar();
	printf("%s", game[0]);
	/*for(; row < GAMESIZE;row++){
		for(;column<GAMESIZE;column++){
			
		}
	}*/
	
	//TODO Compare with posible win conditions
	
	return 0;
}

