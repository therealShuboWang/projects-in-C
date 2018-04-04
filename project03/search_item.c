/* ************************************************************************************************************************************************
 * **************************************************************** 查询信息模块 ******************************************************************
 * ************************************************************************************************************************************************/

#include "header.h"
#include "search.h"
#include <unistd.h>
#include <stdbool.h>

/* 函数声明 */
void search_book(void);


/* 函数定义 */

/*
 * 函数名称：search_book();
 * 函数作用：打印查询列表，接收用户输入的查询信号并调用相应的子函数完成查询工作
 */
void search_book(void)
{
    printf("==========================================================================\n");
    printf("                        ** 1-按编号查询\n");
    printf("                        ** 2-按图书名查询\n");
    printf("                        ** 3-按作者名查询\n");
    printf("                        ** 4-按出版社查询\n");
    printf("                        ** 5-按图书类别查询\n");
    printf("                        ** 6-按出版时间查询\n");
    printf("                        ** 7-按图书价格查询\n");
    printf("                        ** 0-退出查询\n");
    printf("==========================================================================\n\n");    
    sleep(1);

    int choice;
    char check;

    while (true)
    {
        printf("请输入查询编号：");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                search_by_number();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 2:
                search_by_name();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 3:
                search_by_writer();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 4:
                search_by_press();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 5:
                search_by_category();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 6:
                search_by_time();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 7:
                search_by_price();
                sleep(1);
                printf("是否继续查询(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("查询结束！\n");
                    sleep(1);
                    return;
                }
                break;
            case 0:
                printf("您已退出查询！\n");
                sleep(1);
                return;
            default:
                printf("您的选择有误，请重新输入！\n");
                sleep(1);

        }

    }
    
}
