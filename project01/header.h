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

/* 声明全局变量 */
extern int num_in_rank[NUM_OF_RANKS];
extern int num_in_suit[NUM_OF_SUITS];

extern bool straight;
extern bool flush;
extern bool four_of_a_kind;
extern bool three_of_a_kind;
extern int num_of_pairs;

#endif
