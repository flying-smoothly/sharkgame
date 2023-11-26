#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD             15 //0~14��° ĭ  
#define N_COINPOS           12 // Nĭ���� ������ ��ġ�� �Ŵ�. 
#define MAX_COIN            4 //�� ĭ�� �ִ� ������ 4������ ���� �Ŵ�. 

#define MAX_SHARKSTEP       6
#define SHARK_INITPOS      -4

static int board_status[N_BOARD]; // 15���� ������ 1���� �迭��� ǥ��, static�� �ٿ� ���������� extern���� ���� ���� ������ �Ұ����ϰ� �Ѵ� 
static int board_coin[N_BOARD]; // i��° ĭ�� ������ �󸶳� ������ �ֳ��� ǥ�� 

static int board_sharkPosition; // �� �� ��° ĭ�� �ִ��� ���ڷ� ��Ÿ���� 

// main.c���� ȣ���� �ʿ� �Լ� prototype ���·� ���� 

int board_initBoard(void) //���� �ʱ�ȭ 
{
    int i;
     
    for (i=0;i<N_BOARD;i++) //15�� �ݺ��ȴ�. 
    {
        board_status[i]=BOARDSTATUS_OK;
        board_coin[i]= 0;
    }
        
    board_sharkPosition=SHARK_INITPOS;
    //coin �Ҵ�

    for (i=0;i<N_COINPOS;i++) 
    {
        int flag = 0; 
        while(flag == 0) // ����� ������ ������ ������ �ݺ��ؼ� �����Ѵ�. �ö� ������ while ���� ������. �ǵ��ϴ� �����帧�� ������ �� �ִ�. 
        {
               int allocpos = rand()%N_BOARD; //0���� 14������ ���ڰ� �������� ���´�.
               if (board_coin[allocpos] == 0) //�� ������ �����ϸ� �Ҵ��� �� �Ȱ��̹Ƿ� �Ҵ��Ѵ�. 
               {
                   board_coin[allocpos] = rand()%MAX_COIN+1; //if �� �� ������ �����ϸ� while ���� ������.
                   flag =1; 
               }
        }
    }
    
    return 0;

}               
     
int board_printBoardStatus(void) // ��ü ������ ���� ��� 
{
    int i;
    printf("-------------BOARD STATUS-----------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X"); //�� �� �ڸ��� x�� ��� 
        else
            printf("o"); //������ ���� �ʾҴٸ� o�� ��� 
    }
    printf("|\n");
    printf("------------------------------------\n");
    
    return 0;
    
}

void board_getBoardStatus(int pos)
{
    return board_status[pos];
}
int board_getBoardCoin[int pos] //���� 2 
{
     int coin = board_coin[pos]; //pos ��° ����ĭ�� �ִ� ������ �ݴ� ���� 
     board_coin[pos] =0; // board_coin �迭�� ���� ��ȯ�ϸ鼭 �迭 ���� 0���� ���� 
     return coin;
}

//int board_getSharkPosition(void);
int board_stepShark(void)
{
    int step = rand()%MAX_SHARKSTEP +1;
    int i;
    for (i = board_sharkPosition + 1;i <= board_sharkPosition + step; i++)
    {
        if (i>=0 && i<N_BOARD)
           board_status[i] = BOARDSTATUS_NOK;
    }
    
    board_sharkPosition += step;
    
    return board_sharkPosition;
}

