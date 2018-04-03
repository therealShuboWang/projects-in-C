#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

/* 宏定义 */
#define LEN 50

/* 类型定义 */
typedef struct book {                           /* 定义一个结构体类型Book，用来存储一本图书方方面面的信息 */
    int number;                                 /* 结构成员number表示图书编号 */
    char name[LEN];                             /* 结构成员name[]表示图书名 */
    char writer[LEN];                           /* 结构成员writer[]表示作者名 */
    char press[LEN];                            /* 结构成员press[]表示出版社 */
    char category[LEN];                         /* 结构成员category[]表示图书类别 */
    char time[LEN];                             /* 结构成员time[]表示出版时间 */
    double price;                               /* 结构成员price表示图书价格 */

    struct book *next;                          /* 定义指向该结构体的指针，用来找到包含下一本图书信息的结构体 */
} Book;

/* 共享变量声明 */
extern Book *head;
extern Book *tail;


/* 共享函数声明 */
void create_book(void);
void delete_book(void);

#endif
