/* *****************************************************************************************************************************************
 * ******************************************************************* 信息模块 ************************************************************
 * *****************************************************************************************************************************************/

#include "header.h"
#include <stdlib.h>

/* 函数原型 */
void welcome(void);
void game_over(void);

/* 函数定义 */
void welcome(void)
{
    system("clear");

    printf("*****************************************************************************\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                  Welcome                                  *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*****************************************************************************\n");

    printf("press any key, then start!");
    getchar();
}



void game_over(void)
{
    system("clear");

    printf("*****************************************************************************\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                  Game Over                                *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*                                                                           *\n");
    printf("*****************************************************************************\n");
    
}
