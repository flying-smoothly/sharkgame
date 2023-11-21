#include <stdio.h>
#include <stdlib.h>

#define BOARDSTATUS_OK      1 // ������ ���� 1�̸� ������ ĭ 
#define BOARDSTATUS_NOK     0 // ������ ���� 0�̸� �ļյ� ĭ, main.c 0�� 1 �� ���� 

// main.c���� ȣ���� �ʿ� �Լ� prototype ���·� ���� 

int board_initBoard(void); //���� �ʱ�ȭ 
int board_printBoardStatus(void); // ��ü ������ ���� ��� 

int board_getBoardStatus(void); // Ư�� ĭ�� �ļ� ���� ��� 
int board_getBoardCoin(int pos); // ���� ���� ��� 

int board_getSharkPosition(void); // ����� ��ġ ��� 
int board_stepShark(void); // ��� ���� ��� 

