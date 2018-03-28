#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>

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

#endif
