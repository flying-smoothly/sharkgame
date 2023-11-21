#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#define N_BOARD             15 //0~14��° ĭ  
#define BOARDSTATUS_OK      1 // ������ ���� 1�̸� ������ ĭ 
#define BOARDSTATUS_NOK     0 // ������ ���� 0�̸� �ļյ� ĭ 

#define N_COINPOS           12 // Nĭ���� ������ ��ġ�� �Ŵ�. 
#define MAX_COIN            4 //�� ĭ�� �ִ� ������ 4������ ���� �Ŵ�. 
static int board_status[N_BOARD]; // 15���� ������ 1���� �迭��� ǥ��, static�� �ٿ� ���������� extern���� ���� ���� ������ �Ұ����ϰ� �Ѵ� 
static int board_coin[N_BOARD]; // i��° ĭ�� ������ �󸶳� ������ �ֳ��� ǥ�� 

static int board_sharkposition; // �� �� ��° ĭ�� �ִ��� ���ڷ� ��Ÿ���� 

// main.c���� ȣ���� �ʿ� �Լ� prototype ���·� ���� 

int board_initBoard(void) //���� �ʱ�ȭ 
{
    int i;
     
    for (i=0;i<N_BOARD;i++) //15�� �ݺ��ȴ�. 
    {
        board_status[i]=BOARDSTATUS_OK;
        board_coin[i]= 0;
        }
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
    printf("----------------------------------------------------------\n");
    
}

