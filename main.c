#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAXLENGTH 30
#define MAX_DIE   6
#define N_PLAYER  3

#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2


char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"LIVE", "DIE", "END"};

void printPlayerPosition(int player) 
{
     int i;

     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if (i == player_position[player])
         (
            printf("%c", player_name[player][0]);
         )
         else
         (
          if(board_getBoardStatus(i) == BOARDSTATUS_OK)
              printf("");
          else
              printf("X");
         )
     }
      printf("|\n");
}

void printPlaterStatus(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)
     {
           printf("%s : pos %i, coin %i, status %s\n",
                      player_name[i],
                      player_position[i],
                      player_statusString[player_status[i]]);
           printPlayerPosition(i);       
     }
}
 
 
void initPlayer(void)
{
     int i;
     for (i=0;i<N_PLAYER;i++)
     {

         player_position[i] = 0;
         player_coin[i] = 0;
         player_status[N_PLAYER] = PLAYERSTATUS_LIVE;
         printf("Player %i's name: ", i);
         scanf("%s", player_name[i]);
         fflush(stdin); 
     }
     
}
 
 
int rolldie(void)
{
    return rand()%MAX_DIE + 1;
}

int main(int argc, char *argv[])
{
 int cnt;
 int turn;
 int coinResult; 
 
 srand((unsigned) (time(NULL)));

 //opening
 printf("~~start~~~\n");

 //step 1. initialization (player name setting
 board_initBoard();
 initPlayer();
 //player init
 
 //step 2. turn play (do-while)
 cnt = 0;
 turn = 0;
 coinResult = 0;
 do {
     int die_result;
     
    //2-1. status printing
    board_printBoardStatus();
    
    //player status(°¢ÀÚ) 
    printPlaterStatus();
    //2-2. roll die
    die_result = rolldie(); //player turn 
    
    //2-3. move (result)//player turn 
    pos += die_result;
    
    printf("pos : %i (die:%i)\n", pos, die_result);
    
    coinResult += board_getBoardCoin(pos);
    
    printf("coin : %i\n", coinResult);
    
    //2-4. change turn, shark move
    //change turn
    turn = (turn + 1)%N_PLAYER;
    
    //shark move
    cnt++;
 } while(cnt<5); //game end condition
 //step 3. game end (winner printing)

 printf("~~~~~~end~~~\n");
 system("PAUSE");	
 return 0;
}
