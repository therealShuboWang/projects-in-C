/* ***************************************************************************************************************************************
 * ************************************************************ 子查询模块 ***************************************************************
 * ***************************************************************************************************************************************/

#include "header.h"
#include "search.h"
#include <stdbool.h>
#include <string.h>

/* 函数原型 */
void search_by_number(void);
void search_by_name(void);
void search_by_writer(void);
void search_by_press(void);
void search_by_category(void);
void search_by_time(void);
void search_by_price(void);

/* 函数定义 */

/*
 * 函数名称：search_by_number()
 * 函数作用：接收用户输入的编号信息，遍历链表查找是否存在对应的结构体
 * 如果不存在对应该编号的结构体：输出提示信息并结束程序
 * 如果定位到对应该编号的结构体：输出该结构体的完整信息后再结束程序
 */
void search_by_number(void)
{
    /* 接收用户输入的图书编号 */
    int number;
    printf("请输入图书编号：");
    scanf("%d", &number);
    getchar();

    /* 
     * 遍历链表查找是否存在对应的结构体
     * 定义一个指针变量temp，用于遍历过程中的定位操作；遍历操作采用while循环，循环条件为temp != NULL
     * 如果不存在对应该编号的结构体：循环结束时链表已被完全遍历了一遍，最终temp指向NULL
     * 如果定位到对应该编号的结构体：由于系统规定每本图书的编号是唯一的，不存在编号重复的现象
     *                               则在遍历过程中发现的第一个符合条件的结构体，也一定是链表中唯一一个符合条件的结构体
     *                               因此我们在定位到该结构体的同时就输出它的相关信息，并利用return;语句直接结束程序
     */
    Book *temp = head;
    while (temp != NULL)
    {
        if (temp->number == number)
        {
            printf("您所查询的图书信息如下：\n");
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n",
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            return;
        }
        else
            temp = temp->next;
    }
    printf("没有找到符合条件的图书！\n");
}


/*
 * 函数名称：search_by_name(), search_by_writer(), search_by_press(), 
 *           search_by_category(), search_by_time(), search_by_price()
 * 函数作用：接收用户输入的相关图书信息，遍历链表查找是否存在对应的结构体
 *
 * 这6个查询子函数与第1个查询子函数（按编号查询）有所不同：
 * 系统规定每本书的编号信息是唯一的：在遍历过程中发现的第一个符合条件的结构体也一定是链表中唯一一个符合条件的结构体
 * 但是图书的其它信息都是可以重复的：要输出所有符合条件的图书的信息必须将链表完全遍历一遍，每一个结构体都要进行相同的判断操作
 */
void search_by_name(void)
{
    /* 接收用户输入的图书名 */
    char name[LEN];
    printf("请输入图书名：");
    scanf("%s", name);
    getchar();

    /*
     * 遍历链表查找是否存在对应的结构体
     * 定义布尔变量found表示是否找到符合条件的结构体，初始化为false
     * 定义指针变量temp用于遍历过程中的定位操作；遍历操作采用while循环，循环条件为temp != NULL
     * 定位到每一个符合条件的结构体：输出相关信息，将状态变量found设置为true，并将temp指针指向下一个结构体
     * 链表中找不到符合条件的结构体：因为temp指向NULL而结束循环，found的值始终没有机会修改而保持为false
     *                               对变量found进行条件判断从而输出提示信息并立即结束程序
     */
    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}

void search_by_writer(void)
{
    char writer[LEN];
    printf("请输入作者名：");
    scanf("%s", writer);
    getchar();

    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->writer, writer) == 0)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}

void search_by_press(void)
{
    char press[LEN];
    printf("请输入出版社：");
    scanf("%s", press);
    getchar();

    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->press, press) == 0)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}

void search_by_category(void)
{
    char category[LEN];
    printf("请输入出版社：");
    scanf("%s", category);
    getchar();

    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->category, category) == 0)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}


void search_by_time(void)
{
    char time[LEN];
    printf("请输入出版社：");
    scanf("%s", time);
    getchar();

    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->time, time) == 0)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}


void search_by_price(void)
{
    double min_price, max_price;
    printf("请输入价格区间（以空格区分）：");
    scanf("%lf %lf", &min_price, &max_price);
    getchar();

    bool found = false;
    Book *temp = head;
    while (temp != NULL)
    {
        if (min_price <= temp->price && temp->price <= max_price)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n", 
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            found = true; 
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("没有找到符合条件的图书！\n");
        return;
    }
}






