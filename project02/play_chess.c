/* ***********************************************************************************************************************************
 * **************************************************************** 下棋模块 *********************************************************
 * ***********************************************************************************************************************************/

#include "header.h"
#include <unistd.h>             /* 使用sleep()函数时必须包含的头文件 */

/* 函数原型 */
int get_row_coord(void);
int get_column_coord(void);

/* 函数定义 */

/*
 * 该函数提示用户输入落子处所在的行数，用一个整型变量row接收并作为返回值返回
 * 该函数面向用户使用，因此变量row代表的是棋盘实际的行数；我们在后续使用该值时，需要将其映射为程序中二维数组的行坐标(row - 1)
 */
int get_row_coord(void)                                     
{
    if (player == A)
        printf("玩家A：请输入落子处所在的行数！\n");
    else if (player == B)
        printf("玩家B：请输入落子处所在的行数！\n");

    int row;
    printf("row = ");
    scanf("%d", &row);

    while (row < 1 || row > N)                             
    {
        printf("输入错误，超出棋盘的范围!\n");
        sleep(1);
        if (player == A)
            printf("玩家A：请输入落子处所在的行数！\n");
        else if (player == B)
            printf("玩家B：请输入落子处所在的行数！\n");
        printf("row = ");
        scanf("%d", &row);
    }

    return row;
}


/*
 * 该函数提示用户输入落子处所在的列数，用一个整型变量column接收并作为返回值返回
 * 该函数面向用户使用，因此变量column代表的是棋盘实际的列数；我们在后续使用该值时，需要将其映射为程序中二维数组的列坐标(column - 1)
 */
int get_column_coord(void)
{
    if (player == A)
        printf("玩家A：请输入落子处所在的列数！\n");
    else if (player == B)
        printf("玩家B：请输入落子处所在的列数！\n");

    int column;
    printf("column = ");
    scanf("%d", &column);

    while (column < 1 || column > N)
    {
        printf("输入错误，超出棋盘的范围！\n");
        sleep(1);
        if (player == A)
            printf("玩家A：请输入落子处所在的行数！\n");
        else if (player == B)
            printf("玩家B：请输入落子处所在的行数！\n");
        printf("column = ");
        scanf("%d", &column);
    }

    return column;
}











