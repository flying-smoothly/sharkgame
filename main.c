#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define MAX_DIE

void opening(void)
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
     
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}

int main(int argc, char *argv[])
{
    int pos=0;
    srand((unsigned)time(NULL));
    
    //0. opening
    opening();
    
    //1. 초기화 & 플레이어 이름 결정
    board_initBoard();
    
    //2. 반복문 (플레이어 턴)
    do {
        int step = rolldie();
        int coinResult;
        char c;
        
        board_printBoardStatus();
        
        pos += step;
        //printf()
        coinResult = board_getBoardCoin(pos);
        
        printf("Press any key to continue:");
        scanf("%d", &c);
        fflush(stdin);
      //2-1. 플레이어의 상태 출력
      //2-2. 주사위 던지기
      //2-3. 이동
      //2-4. 동전을 줍기.
      //2-5. 다음 턴으로 간다. 
      //2-6. if (조건: 모든 플레이어가 한번씩 턴을 돈다.)
       // 상어 동작 
       } while(1);
       
      //3. 정리  (승자 계산, 출력 등) 
  
  system("PAUSE");	
  return 0;
} //실습 3번까지 마무리하기. 
