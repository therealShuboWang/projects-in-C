/* ******************************************************************************************************************************
 * ****************************************************** 分析输出模块 **********************************************************
 * ******************************************************************************************************************************/

#include "header.h"

extern int num_in_rank[NUM_OF_RANKS];
extern int num_in_suit[NUM_OF_SUITS];
extern bool straight;
extern bool flush;
extern bool four_of_a_kind;
extern bool three_of_a_kind;
extern int num_of_pairs;



void analyze_hand(void)
{
    straight = false;
    flush = false;
    four_of_a_kind = false;
    three_of_a_kind = false;
    num_of_pairs = 0;

    /*
     * 首先检查是否出现同花
     * 出现同花意味着某种花色连续出现了5次
     * 对应到程序中就是数组num_in_suit中有且仅有一个元素的值为5，而其余3个元素值均为0
     */
    for (int i = 0; i < NUM_OF_SUITS; i++)
    {
        if (num_in_suit[i] == CARDS_IN_HAND)
        {
            flush = true;
        }
    }

    /*
     * 接着检查是否出现顺子
     * 出现顺子意味着从某一个等级开始，包括它在内和往后的四个等级出现且仅出现一次
     * 对应到程序中就是数组num_in_rank中从某一个位置开始，该位置及其后四个位置上的元素值均为1，而其余8个元素值均为0 
     */
    int j = 0;                                                          /* 定义变量表示数组num_in_rank的下标 */
    int count = 0;                                                      /* 定义变量充当计数器：每找到相邻且值为1的元素就自增1 */
    while (num_in_rank[j] == 0)                                         /* 首先找到数组num_in_rank中第一个值为1的元素的位置，从该位置进行顺子判断 */
    {
        j++;
    }
    for (; j < CARDS_IN_HAND && num_in_rank[j] == 1; j++)               /* 从第一个位置起，每找到相邻且值为1的元素就将计数器count自增1 */
    {
        count++; 
    }
    if (count == CARDS_IN_HAND)                                        /* 循环完成后通过计数器的值是否等于5来判断这一手牌是否构成顺子 */
    {
        straight = true;
    }

    /*
     * 接着检查是否出现三张、四张、两对、一对这四种情况
     * 这四种情况都是检查相同等级的出现次数，对应到程序中就是检查数组num_in_rank中元素的值
     */
    for (int i = 0; i < NUM_OF_RANKS; i++)
    {
        if (num_in_rank[i] == 4)
        {
            four_of_a_kind = true;
        }
        if (num_in_rank[i] == 3)
        {
            three_of_a_kind = true;
        }
        if (num_in_rank[i] == 2)
        {
            num_of_pairs++;
        }
    }
}





void print_result(void)
{
    if (straight && flush)
    {
        printf("同花顺！");
    }
    else if (four_of_a_kind)
    {
        printf("四张！");
    }
    else if (three_of_a_kind && num_of_pairs == 1)
    {
        printf("葫芦！");
    }
    else if (flush)
    {
        printf("同花！");
    }
    else if (straight)
    {
        printf("顺子！");
    }
    else if (three_of_a_kind)
    {
        printf("三张！"); 
    }
    else if (num_of_pairs == 2)
    {
        printf("两对！");
    }
    else if (num_of_pairs == 1)
    {
        printf("一对！");
    }
    else
    {
        printf("其它！");
    }

    printf("\n\n");
}
