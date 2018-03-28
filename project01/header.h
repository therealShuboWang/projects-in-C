#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdbool.h>

/*
 * 进行宏定义
 * 一副牌按等级划分可以划分为13个等级(rank)：2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A
 * 一副牌按花色分类可以分类出4 种花色(suit)：方块(club), 梅花(diamond), 红桃(heart), 黑桃(spade)
 * 按照游戏要求，用户每轮抽出5张牌，然后按照等级和花色进行综合分类
 * */
#define NUM_OF_RANKS 13
#define NUM_OF_SUITS 4
#define CARDS_IN_HAND 5

/*
 * 定义全局变量
 * num_in_rank数组用来记录在每一轮游戏中，用户抽到的5张牌中出现的5次等级
 * num_in_suit数组用来记录在每一轮游戏中，用户抽到的5张牌中出现的5次花色
 * 注意：
 * 1. 由于构成游戏的三个函数之间都需要这两个数组记录的信息，因此将这两个数组定义为全局变量，实现数据共享
 * 2. 由于全局变量具有静态存储期限，因此新一轮游戏开始前这两个数组中还保留着上一轮的数据值，所以有必要在每次游戏开始前对这两个数组元素全部重新赋值为0
 * 3. 我们通过在read_cards函数中使用for循环实现数组元素重新赋值为0，而不是在定义这两个数组时进行初始化操作
 */
int num_in_rank[NUM_OF_RANKS];
int num_in_suit[NUM_OF_SUITS];


/*
 * 定义全局变量
 * 布尔变量straight, flush, four_of_a_kind, three_of_a_kind分别表示本轮游戏抽取的5张牌所能形成的4种基本结果
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
bool straight;
bool flush;
bool four_of_a_kind;
bool three_of_a_kind;
int num_of_pairs;

#endif
