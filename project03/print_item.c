/* ***************************************************************************************************************************************
 * **************************************************************** 显示图书模块 *********************************************************
 * ***************************************************************************************************************************************/

#include "header.h"
#include <unistd.h>

/* 函数原型 */
void show_book(void);

/* 函数定义 */
void show_book(void)
{
    if (head == NULL)
    {
        printf("当前图书管理系统为空！\n");
        sleep(1);
    }
    else
    {
        printf("图书列表如下：\n");
        Book *temp = head;
        while (temp != NULL)
        {
            printf("number: %d\tname: %s\twriter: %s\tpress: %s\tcategory: %s\ttime: %s\tprice: %.2f\n",
                    temp->number, temp->name, temp->writer, temp->press, temp->category, temp->time, temp->price);
            temp = temp->next;
        }
        sleep(1);
    }
}
