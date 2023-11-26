#include <stdio.h>
#include <stdlib.h>

#ifndef BOARD_H
#define BOARD_H

#define BOARDSTATUS_OK      1 // ������ ���� 1�̸� ������ ĭ 
#define BOARDSTATUS_NOK     0 // ������ ���� 0�̸� �ļյ� ĭ, main.c 0�� 1 �� ���� 

// main.c���� ȣ���� �ʿ� �Լ� prototype ���·� ���� 

int board_initBoard(void); //���� �ʱ�ȭ 
int board_printBoardStatus(void); // ��ü ������ ���� ��� 

int board_getBoardStatus(int pos); // Ư�� ĭ�� �ļ� ���� ��� 
int board_getBoardCoin(int pos); // ���� ���� ��� 

//int board_getSharkPosition(void); // ����� ��ġ ��� 
int board_stepShark(void); // ��� ���� ��� 

#endif /* BOARD_H */
