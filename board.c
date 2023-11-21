#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#define N_BOARD             15 //0~14번째 칸  
#define BOARDSTATUS_OK      1 // 정수의 값이 1이면 멀쩡한 칸 
#define BOARDSTATUS_NOK     0 // 정수의 값이 0이면 파손된 칸 

#define N_COINPOS           12 // N칸까지 동전을 배치할 거다. 
#define MAX_COIN            4 //한 칸에 최대 동전을 4개까지 놓을 거다. 
static int board_status[N_BOARD]; // 15개의 정수가 1차원 배열들로 표현, static을 붙여 전역변수나 extern으로 변수 값에 개입이 불가능하게 한다 
static int board_coin[N_BOARD]; // i번째 칸이 동전을 얼마나 가지고 있나를 표현 

static int board_sharkposition; // 상어가 몇 번째 칸에 있는지 숫자로 나타낸다 

// main.c에서 호출할 필요 함수 prototype 형태로 정의 

int board_initBoard(void) //보드 초기화 
{
    int i;
     
    for (i=0;i<N_BOARD;i++) //15번 반복된다. 
    {
        board_status[i]=BOARDSTATUS_OK;
        board_coin[i]= 0;
        }
    //coin 할당
    for (i=0;i<N_COINPOS;i++) 
    {
        int flag = 0; 
        while(flag == 0) // 깃발이 내려가 있으면 과정을 반복해서 실행한다. 올라가 있으면 while 문을 나간다. 의도하는 제어흐름을 가져갈 수 있다. 
        {
               int allocpos = rand()%N_BOARD; //0부터 14까지의 숫자가 랜덤으로 나온다.
               if (board_coin[allocpos] == 0) //이 조건을 만족하면 할당이 안 된것이므로 할당한다. 
               {
                                        board_coin[allocpos] = rand()%MAX_COIN+1; //if 문 내 조건을 만족하면 while 문을 나간다.
                                        flag =1; 
                                        }
               }
        }
        return 0;
}               
     
int board_printBoardStatus(void) // 전체 보드의 상태 출력 
{
    int i;
    printf("-------------BOARD STATUS-----------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X"); //상어가 온 자리는 x를 출력 
        else
            printf("o"); //상어까지 오지 않았다면 o를 출력 
    }
    printf("|\n");
    printf("----------------------------------------------------------\n");
    
}

