#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE   6

int rolldie(void)
{
    return rand()%MAX_DIE + 1;
}

int main(int argc, char *argv[])
{
 int cnt;
 int pos;
 srand((unsigned) (time(NULL)));

 //opening
 printf("~~start~~~\n");

 //step 1. initialization (player name setting
 board_initBoard();
 
 //step 2. turn play (do-while)
 cnt = 0;
 pos = 0;
 do {
     int die_result;
     int coinResult;
     
    //2-1. status printing
    board_printBoardStatus();
    
 
    //2-2. roll die
    die_result = rolldie();
    
    //2-3. move (result)
    pos += die_result;
    
    printf("pos : %i (die:%i)\n", pos, die_result);
    
    coinResult = board_getBoardCoin(pos);
    
    printf("coin : %i\n");
    
    //2-4. change turn, shark move
    
    cnt++;
 } while(cnt<5);
 //step 3. game end (winner printing)

 printf("~~~~~~end~~~\n");
 system("PAUSE");	
 return 0;
}
