#include <stdio.h>
#include <stdlib.h>

#ifndef BOARD_H
#define BOARD_H

#define BOARDSTATUS_OK      1 // 정수의 값이 1이면 멀쩡한 칸 
#define BOARDSTATUS_NOK     0 // 정수의 값이 0이면 파손된 칸, main.c 0과 1 뜻 이해 

// main.c에서 호출할 필요 함수 prototype 형태로 정의 

int board_initBoard(void); //보드 초기화 
int board_printBoardStatus(void); // 전체 보드의 상태 출력 

int board_getBoardStatus(int pos); // 특정 칸의 파손 여부 출력 
int board_getBoardCoin(int pos); // 동전 습득 명령 

//int board_getSharkPosition(void); // 상어의 위치 출력 
int board_stepShark(void); // 상어 전진 명령 

#endif /* BOARD_H */
