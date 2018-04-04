/* *************************************************************************************************************************************
 * ************************************************************ 修改图书模块 ***********************************************************
 * *************************************************************************************************************************************/

#include "header.h"
#include <stdbool.h>
#include <unistd.h>

/* 函数原型 */
void modify_book(void);

/* 函数定义 */

/*
 * 函数名称：modify_book()
 * 函数作用：接收用户输入的图书编号，遍历链表查找是否存在对应的结构体
 *           如果不存在对应该编号的结构体：输出提示信息并结束程序
 *           如果定位到对应该编号的结构体：进一步让用户选择要修改的具体信息并执行对应的修改操作
 */
void modify_book(void)
{
    /* 接收用户输入的图书编号 */
    int number;
    printf("请输入要修改的图书的编号：");
    scanf("%d", &number);
    getchar();

    /*
     * 遍历链表查找是否存在对应的结构体
     * 定义一个指针变量temp，用于遍历过程中的定位操作；遍历操作采用while循环，循环条件为temp != NULL
     * 如果不存在对应该编号的结构体：则始终没有机会执行循环体中的break语句，而是最终执行到不满足循环条件时才终止
     *                               此时链表已被完全遍历了一遍，最终temp指向NULL
     * 如果定位到对应该编号的结构体：则经过几次循环后由于满足了循环体内部的if条件判断而执行break语句，直接跳出循环
     *                               此时链表并没有被遍历完全，最终temp指向链表中对应编号的那个结构体
     */
    Book *temp = head;
    while (temp != NULL)
    {
        if (temp->number == number)
            break;
        temp = temp->next;
    }

    /* 如果不存在对应该编号的结构体 */
    if (temp == NULL)
    {
        printf("没有找到对应该编号的图书！\n");
        sleep(1);
        return;
    }

    /*
     * 如果定位到该编号的结构体：
     * 输出提示信息供用户选择，程序根据用户选择的结果执行不同的修改操作
     */
    printf("==============================================================================\n\n");
    printf("        ** 1-编号           2-图书名            3-作者名        **\n");
    printf("        ** 4-出版社         5-图书类别          6-出版时间      **\n");
    printf("        ** 7-价格           0-放弃修改                          **\n");
    printf("\n==============================================================================\n");
    sleep(1);

    /*
     * 由于允许用户在一次修改操作中对图书的多个信息进行修改，因此程序主体部分采用永真循环反复执行
     * 定义整型变量choice接收修改操作的编号，定义字符型变量check判断用户是否希望继续修改其它信息
     * 程序内部的break语句用于结束一轮的switch判断；程序内部的return;语句用于结束整个修改程序
     */
    int choice;
    char check;

    while (true)
    {
        printf("请输入您要进行的修改操作的编号：");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("请输入新的图书编号：");
                scanf("%d", &temp->number);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1); 
                    return;
                }
                break;
            case 2:
                printf("请输入新的图书名：");
                scanf("%s", temp->name);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 3:
                printf("请输入新的作者名：");
                scanf("%s", temp->writer);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 4:
                printf("请输入新的出版社：");
                scanf("%s", temp->press);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 5:
                printf("请输入新的图书类别：");
                scanf("%s", temp->category);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 6:
                printf("请输入新的出版时间：");
                scanf("%s", temp->time);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 7:
                printf("请输入新的图书价格：");
                scanf("%lf", &temp->price);
                getchar();
                printf("修改成功！\n");
                sleep(1);
                printf("是否继续修改(y/n)：");
                scanf("%c", &check);
                getchar();
                if (check == 'n')
                {
                    printf("修改完成！\n");
                    sleep(1);
                    return;
                }
                break;
            case 0:
                printf("您已放弃修改！\n");
                sleep(1);
                return;
            default:
                printf("您的选择有误，请重新输入！\n");
                sleep(1);
        }
    }
}
