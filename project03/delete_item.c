/* ******************************************************************************************************************************************
 * **************************************************************** 删除图书模块 ************************************************************
 * ******************************************************************************************************************************************/

#include "header.h"
#include <unistd.h>

/* 函数原型 */
void delete_book(void);

/* 函数定义 */

/*
 * 函数名称：delete_book()
 * 函数作用：接收用户输入的图书编号，遍历链表查找是否存在对应的结构体
 * 如果不存在对应该编号的结构体：输出提示信息并结束程序
 * 如果定位到对应该编号的结构体：根据该结构体在链表中所处的位置，妥善地将其从链表中删除
 */
void delete_book(void)
{
    /* 接收用户输入的图书编号 */
    int number;
    printf("请输入要删除的图书的编号：");
    scanf("%d", &number);

    /*
     * 遍历链表查找是否存在对应的结构体
     * 定义两个指针变量current和previous，用于在遍历过程的中定位操作
     * 分别将current和previous初始化为head和NULL，两者在遍历过程中从初始指向对象开始，依次指向后一个对象
     * 遍历操作采用while循环进行，循环的条件为current != NULL
     * 如果不存在对应该编号的结构体：则始终没有机会执行循环体中的break语句跳出，而是最终执行到不满足循环条件时才终止
     *                               此时链表已被完全遍历了一遍，最终current指向NULL，previous指向链表中的最后一个结构体
     * 如果定位到对应该编号的结构体：则经过几次循环后，由于满足了循环体内部的if条件判断而执行break语句，直接跳出循环
     *                               此时链表并没有被遍历完全，最终current指向链表中对应编号的那个结构体，而previous指向它前面的那个结构体
     * 使用两个指针变量是为了有效地执行删除操作：将因为删除结构体而断开的链表重新连接起来
     */
    Book *current = head;
    Book *previous = NULL;

    while (current != NULL)
    {
        if (current->number == number)
            break;
        else
        {
            previous = current;
            current = current->next;
        }
    }

    
    /* 如果不存在对应该编号的结构体 */
    if (current == NULL)
    {
        printf("没有找到对应该编号的图书！\n");
        sleep(1);
        return;
    }


    /*
     * 如果定位到对应该编号的结构体:
     * 1. 该链表由一个结构体组成，对应编号的结构体就是这唯一的一个结构体
     * 2. 该链表由多个结构体组成，对应编号的结构体位于链表的起始位置
     * 3. 该链表由多个结构体组成，对应编号的结构体位于链表的末尾位置
     * 4. 该链表由多个结构体组成，对应编号的结构体位于链表的中间位置
     */
    if (current == head && tail == head)
        head = tail = NULL;
    else if (current == head && tail != head)
    {
        head = current->next;
        current->next = NULL;
    }
    else if (current == tail)
    {
        previous->next = NULL;
        tail = previous;
    }
    else
    {
        previous->next = current->next;
        current->next = NULL;
    }

    printf("删除成功！\n");
    sleep(1);

}
