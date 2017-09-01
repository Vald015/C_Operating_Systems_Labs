
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Constants */
#define P1 X		/* Player 1 symbol */
#define P2 Y		/* Player 2 Symbol */
#define EMPTY .			/* Empty space */
/* String constants */
#define XWON "Player X Won\n"				/* Player 1 won string */
#define YWON "Player Y Won\n"				/* Player 2 won string  */
#define Draw "Draw Game\n"				/* Tie game string */
#define GNC "Game  has not completed\n"	/* Incomplete game string */
#define GO "Game Over\n"					/* Game over string */


int main() {
	
	int notc = 0;
	
	printf("Enter notc: \n");
	scanf("%d", &notc);
	getchar();
	printf("notc = %d\n",notc);
	
	return 0;
}
