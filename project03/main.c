/* *********************************************************************************************************************************************
 * **************************************************************** 主函数模块 *****************************************************************
 * *********************************************************************************************************************************************/

#include "header.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/* 定义全局变量 */
Book *head = NULL;
Book *tail = NULL;

int main(void)
{
    int choice;
    char check;

    while (true)
    {
        system("clear");

        printf("                        -------------------------\n");
        printf("                            * 图书管理系统 *\n");
        printf("                        -------------------------\n");
        printf("        **************************************************************\n");
        printf("                            * 1-录入图书\n");
        printf("                            * 2-删除图书\n");
        printf("                            * 3-修改图书\n");
        printf("                            * 4-查询图书\n");
        printf("                            * 5-图书列表\n");
        printf("                            * 0-退出系统\n");
        printf("        **************************************************************\n\n");

        sleep(1);
        printf("请输入操作编号：");
        scanf("%d", &choice);
        getchar();
        system("clear");

        switch (choice)
        {
            case 1:
                printf("注意：当输入的图书编号为0时表示结束录入操作！\n");
                sleep(1);
                create_book();

                printf("是否继续其它操作(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("感谢您的使用！\n");
                    sleep(1);
                    return 0;
                }
                break;
            case 2:
                delete_book(); 
                printf("是否继续其它操作(y/n)：");
                scanf("%c", &check);
                if (check == 'n')
                {
                    printf("感谢您的使用！\n");
                    sleep(1);
                    return 0;
                }
                break;
            case 3:
                modify_book();
                printf("是否继续其它操作(y/n)：");
                scanf("%c", &check);
                if (check == 'n')
                {
                    printf("感谢您的使用！\n");
                    sleep(1);
                    return 0;
                }
                break;
            case 4:
                search_book();
                printf("是否继续其它操作(y/n)：");
                scanf("%c", &check);
                if (check == 'n')
                {
                    printf("感谢您的使用！\n");
                    sleep(1);
                    return 0;
                }
                break;
            case 5:
                show_book();
                printf("是否继续其它操作(y/n)：");
                scanf("%c", &check);
                if (check == 'n')
                {
                    printf("感谢您的使用！\n");
                    sleep(1);
                    return 0;
                }
                break;
            case 0:
                printf("感谢您的使用！\n");
                sleep(1);
                return 0;
            default:
                printf("您的输入有误，请重新输入！\n");
                sleep(1);
        }
    }
}
