#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define N_BOARD          15
#define MAX_CHARNAME     200
#define N_PLAYER         3
#define MAX_DIE          6

#define PLAYERSTATUS_LIVE   0 //if (player_status[0] == PLAYERSTATUS_LIVE)
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0-live, 1-die, 2-end
char player_statusString[3][MAX_CHARNAME]={"LIVE","DIE","END"};

void opening(void) //���� ���� ���� "YomYumYum" 
{
     printf("=============================================\n");
     printf("=============================================\n");
     printf("=============================================\n");
     printf("==================YomYumYum==================\n");
     printf("=============================================\n");
     printf("=============================================\n");
     printf("=============================================\n");
     printf("=============================================\n");
}
     
int rolldie(void) //�ֻ��� ���� ������ ������ ���� �������� ���� ���� 
{
    return rand()%MAX_DIE+1;
}

void printPlayerPosition(int player)
{
     int i;
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if (i== player_position[player])
             printf("%c", player_name[player][0]);
         else
         {
             if (board_getBoardStatus(i) == BOARDSTATUS_NOK) // board_getBoardStatus ���� �Ұ�ȣ ���� 
                 printf("X");
             else
                 printf(" ");
         }
     }
     printf("|\n");
}

void printPlayerStatus(void)
{
     int i;
     printf("player status ---\n");
     for (i=0;i<N_PLAYER;i++)
     {
         printf("%s : pos  %i, coin %i, status : %s\n",
                player_name[i], player_position[i]. player_coin[i], player_statusString [player_status[i]]);
     }
     printf("-----------------\n");
}

void checkDie (void)
{
     int i;
     for (i=0; i<N_PLAYER; i++)
         if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
             player_status[i] = PLAYERSTATUS_DIE;
}

int main(int argc, char *argv[])
{
    int pos=0;
    int i;
    int turn=0;
    
    srand((unsigned)time(NULL)); //���� ���� 
    
    //0. opening �ݺ��Ǵ� �����̱⿡ �Ϲ������� �ڵ��� ��. 
    opening();
    
    //1. �ʱ�ȭ & �÷��̾� �̸� ���� initiallization 1-1. board init
    board_initBoard();
    // 1-2: initialize player
    for (i=0;i<N_PLAYER;i++) //��ũ�� ��� 3��������� ������ ���� ����� ��������.  
    {
        player_position[i] = 0;
        player_coin[i] = 0; 
        player_status[i] = PLAYERSTATUS_LIVE;
        //player_name
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]); //& �ʿ����. ��ü�� �����Ϳ� �ش�Ǳ� �����̴�.
    }
    
    //2. �ݺ��� (�÷��̾� ��) 1-2. player unit
    do {
        int step;
        int coinResult;
        char c;
        
        if (player_status[turn] != PLAYERSTATUS_LIVE) //live: ����, die, end: �� 
        {
             turn = (turn +1)%N_PLAYER; 
             continue;
        }
       
      //2-1. �÷��̾��� ���� ��� game loop 2-1. status printing
      board_printBoardStatus();
      for (i=0;i<N_PLAYER;i++)
          printPlayerPosition(i);
      printPlayerStatus();
      
      
      //2-2. �ֻ��� ������ 2-2. roll die
      printf("%s turn!!", player_name[turn]);
      printf("press any key to roll a die!\n");
      scanf("%c", &c); //���� 1 
      while (getchar() != '\n'); // ����� ���信�� ���۶�� ��ġ�� ����� ��. ���ۿ� �׿��ٰ� ���α׷��� �������� ��. ǥ���Է��� fflush ��Ű�ڴ�. fflush(stdin); ���� 2 
      step = rolldie();
      
      //2-3. �̵� 2-3. moving
      player_position[turn] += step;
      if (player_position[turn] >= N_BOARD)
          player_position[turn] = N_BOARD-1;  
          
          if (player_position[turn] == N_BOARD-1)
              player_status[turn] = PLAYERSTATUS_END;
        //printf()
        
      //2-4. ������ �ݱ�. 2-4. get coin
      coinResult = board_getBoardCoin(player_position[turn]);
      player_coin[turn] += coinResult;
        //print()
        
      //2-5. ���� ������ ����. 2-5. check end & next turn
      turn = (turn +1)%N_PLAYER; //wrap around 
      
      //2-6. if (����: ��� �÷��̾ �ѹ��� ���� ����.)
      if (turn == 0)
      {
                // ��� ���� 
               int shar_pos = board_stepShark();
               //printf(); �� �̵��ߴ�
               checkDie();
      }
    } while( !�줧_��()); // ������ ������ ���� �ݺ��� �������� �ڵ��ϱ� !!! 
       
      //3. ����  (���� ���, ��� ��) 
  int game_end(void)
  {
      int i;
      int flag_end=1;
      
      //if all the players are died?
      for (i=0; i<N_PLAYER;i++)
      {
          if (player_status[i] == PLAYERSTATUS_LIVE)
          {
                               flag_end = 0;
                               break;
                              }
          }
          return flag_end;
      }
      
  int getAlivePlayer(void)
  {
      int i;
      int cnt=0;
      for (i=0; i<N_PLAYER;i++)
      {
          if (player_status[i] == PLAYERSTATUS_END)
              cnt++;
      }
              
      return cnt;
  }
  int getWinner(void)
  {
      int i;
      int winner=0;
      int max_coin=-1;
      
      for (i=0;i<N_PLAYER;i++)
      {
          if (player_coin[i] > max_coin[i])          
          winner = i;
   
   return winner;
  }
  
  system("PAUSE");	
  return 0;
  
  } 

//�ǽ� 3������ �������ϱ�. 
//�ǽ� 6 ���� ��ȿ ���� �� �Ʒ� ����ִ� �÷��̾� �ѿ��� ����Ǿ��. �� ������ �ִµ� �״�� ¥�� ����� ����. 
