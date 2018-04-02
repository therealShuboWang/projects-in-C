#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

/* 进行宏定义，宏N表示棋盘的大小 */
#define N 19

/*
 * 进行类型定义
 * 定义枚举类型Type表示棋子的类型：NONE表示当前位置上没有棋子，BLACK表示黑子，WHITE表示白子
 * 定义枚举类型Player表示游戏此刻该落子的玩家：A表示轮到玩家A落子，B表示轮到玩家B落子 
 */
typedef enum {NONE, BLACK, WHITE} Type;            
typedef enum {A, B} Player;                         


/* 声明全局变量 */
extern Type pieces[N][N];
extern Player player;

/* 函数原型 */
void draw_board(void);

int get_row_coord(void);
int get_column_coord(void);

Type check_result(int x, int y);

void welcome(void);
void game_over(void);

#endif

