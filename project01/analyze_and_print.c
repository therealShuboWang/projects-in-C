/* ******************************************************************************************************************************
 * ****************************************************** 分析输出模块 **********************************************************
 * ******************************************************************************************************************************/

#include "header.h"
#include <stdbool.h>

extern int num_in_rank[NUM_OF_RANKS];
extern int num_in_suit[NUM_OF_SUITS];

/*
 * 定义外部变量：在本文件中的两个函数中传递使用
 * 布尔量变量straight, flush, four_of_a_kind, three_of_a_kind分别表示本轮游戏抽取的5张牌所能形成的4种基本结果
 * 布尔变量初始化均为false，如果通过函数的分析发现本轮游戏出现了某种结果，则将对应布尔量的值设置为true
 * straight        : 顺子（5张牌的等级连续）
 * flush           : 同花（5张牌的花色相同）
 * four_of_a_kind  : 四张（4张牌的等级相同） 
 * three_of_a_kind : 三张（3张牌的等级相同）
 * 整型变量num_of_pairs初始化为0，可能取值为1或2，代表了本轮游戏抽取的5张牌所能形成的另外两种基本结果
 * num_of_pairs = 2: 两对（2对牌的等级相同）
 * num_of_pairs = 1: 一对（1对牌的等级相同）
 *
 * 注意：
 * 除了上述所列的6种基本情况外，还有两种由基本情况组合出的结果
 * straight flush : 同花顺（5张牌的等级连续，花色相同）
 * full horse     : 葫芦（5张牌中有3张牌为同一个等级，另外2张牌为另一种等级）
 * 如果5张牌可以形成上述8种结果中的多种结果，则程序将自动选择最好的一种情况输出
 * 8中结果的好坏排序：同花顺 > 四张 > 葫芦 > 同花 > 顺子 > 三张 > 两对 > 一对
 */
bool straight = false;
bool flush = false;
bool four_of_a_kind = false;
bool three_of_a_kind = false;
int num_of_pairs = 0;


void analyze_hand(void)
{
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
