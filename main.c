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

void opening(void) //게임 시작 문구 "YomYumYum" 
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
     
int rolldie(void) //주사위 굴릴 때마다 무작위 숫자 나오도록 난수 설정 
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
             if (board_getBoardStatus(i) == BOARDSTATUS_NOK) // board_getBoardStatus 다음 소괄호 주의 
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
    
    srand((unsigned)time(NULL)); //난수 생성 
    
    //0. opening 반복되는 과정이기에 일반적으로 코딩할 것. 
    opening();
    
    //1. 초기화 & 플레이어 이름 결정 initiallization 1-1. board init
    board_initBoard();
    // 1-2: initialize player
    for (i=0;i<N_PLAYER;i++) //매크로 대신 3집어넣으면 위에서 숫자 변경시 에러난다.  
    {
        player_position[i] = 0;
        player_coin[i] = 0; 
        player_status[i] = PLAYERSTATUS_LIVE;
        //player_name
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]); //& 필요없다. 자체가 포인터에 해당되기 때문이다.
    }
    
    //2. 반복문 (플레이어 턴) 1-2. player unit
    do {
        int step;
        int coinResult;
        char c;
        
        if (player_status[turn] != PLAYERSTATUS_LIVE) //live: 거짓, die, end: 참 
        {
             turn = (turn +1)%N_PLAYER; 
             continue;
        }
       
      //2-1. 플레이어의 상태 출력 game loop 2-1. status printing
      board_printBoardStatus();
      for (i=0;i<N_PLAYER;i++)
          printPlayerPosition(i);
      printPlayerStatus();
      
      
      //2-2. 주사위 던지기 2-2. roll die
      printf("%s turn!!", player_name[turn]);
      printf("press any key to roll a die!\n");
      scanf("%c", &c); //수정 1 
      while (getchar() != '\n'); // 입출력 개념에서 버퍼라는 장치를 사용한 것. 버퍼에 쌓였다가 프로그램에 들어오도록 함. 표준입력을 fflush 시키겠다. fflush(stdin); 수정 2 
      step = rolldie();
      
      //2-3. 이동 2-3. moving
      player_position[turn] += step;
      if (player_position[turn] >= N_BOARD)
          player_position[turn] = N_BOARD-1;  
          
          if (player_position[turn] == N_BOARD-1)
              player_status[turn] = PLAYERSTATUS_END;
        //printf()
        
      //2-4. 동전을 줍기. 2-4. get coin
      coinResult = board_getBoardCoin(player_position[turn]);
      player_coin[turn] += coinResult;
        //print()
        
      //2-5. 다음 턴으로 간다. 2-5. check end & next turn
      turn = (turn +1)%N_PLAYER; //wrap around 
      
      //2-6. if (조건: 모든 플레이어가 한번씩 턴을 돈다.)
      if (turn == 0)
      {
                // 상어 동작 
               int shar_pos = board_stepShark();
               //printf(); 상어가 이동했다
               checkDie();
      }
    } while( !흠ㄷ_둥()); // 게임이 끝나는 순간 반복이 끝나도록 코딩하기 !!! 
       
      //3. 정리  (승자 계산, 출력 등) 
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

//실습 3번까지 마무리하기. 
//실습 6 게임 종효 오른 쪽 아래 살아있는 플레이어 한에서 진행되어야. 논리 오류가 있는데 그대로 짜도 상관은 없음. 
