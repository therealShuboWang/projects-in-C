/* **********************************************************************************************************************
 * ******************************************************** 读牌模块 ****************************************************
 * **********************************************************************************************************************/

#include "header.h"
#include <stdlib.h>
#include <stdbool.h>

extern int num_in_rank[NUM_OF_RANKS];
extern int num_in_suit[NUM_OF_SUITS];

void read_cards(void)
{
    /* 每轮游戏开始前，将记录用户抽到的牌的等级和花色的两个数组全部赋值为0 */
    for (int i = 0; i < NUM_OF_RANKS; i++)
    {
        num_in_rank[i] = 0;
    }
    for (int j = 0; j < NUM_OF_SUITS; j++)
    {
        num_in_suit[j] = 0;
    }

    /* 定义布尔型数组card_exists，表示对应的牌（等级和花色的组合）是否在游戏中出现
     * 该数组元素全部被初始化为false，如果这种牌在本轮游戏的本次抽牌中被抽到，则设置它所对应的元素为true
     * 每一轮游戏进行后，该数组中应该有且仅有5个元素被设置为true（设置为true的操作只能进行一次），其余元素均保持为false
     * 如果有对应的牌不在该数组所表示的范围内，则说明用户抽到的为"Bad card"；如果有同一张牌出现了两次，则说明用户抽到的为"Duplicate card"
     */
    bool card_exists[NUM_OF_RANKS][NUM_OF_SUITS] = {false};

    int cards_read = 0;
    bool bad_card = false;
    char rank, suit;
    while (cards_read < CARDS_IN_HAND)          /* 通过计数器cards_read控制循环的次数，按照要求每轮游戏用户能且仅能进5次抽牌 */
    {
        printf("Enter a card: ");               /* 用户输入一张牌，在程序中体现为两个字符：第一个字符代表等级，第二个字符代表花色 */
        rank = getchar();                       /* 用变量rank接受第一个代表等级的字符 */
        switch (rank)                           /* 由于变量rank会被用作全局数组变量num_in_rank的下标，因此在接收用户输入后统一将其转化从0开始的连续数字 */
        {
            case '0':
                exit(EXIT_SUCCESS);
            case '2':
                rank = 0;
                break;
            case '3':
                rank = 1;
                break;
            case '4':
                rank = 2;
                break;
            case '5':
                rank = 3;
                break;
            case '6':
                rank = 4;
                break;
            case '7':
                rank = 5;
                break;
            case '8':
                rank = 6;;
                break;
            case '9':
                rank = 7;
                break;
            case 't': case 'T':
                rank = 8;
            case 'j': case 'J':
                rank = 9;
                break;
            case 'q': case 'Q':
                rank = 10;
                break;
            case 'k': case 'K':
                rank = 11;
                break;
            case 'a': case 'A':
                rank = 12;
                break;
            default:                            /* 如果用户输入的等级不在罗列的13个中，则说明用户输入了一个非法的牌面，因此设置变量bad_card为true */
                bad_card = true;
        }
        suit = getchar();                       /* 用变量suit接受第二个代表花色的字符 */        
        switch (suit)                           /* 由于变量suit会被用作全局数组变量num_in_suit的下标，因此在接受用户输入后统一将其转化为从0开始的连续数字 */
        {
            case 'c': case 'C':
                suit = 0;
                break;
            case 'd': case 'D':
                suit = 1;
                break;
            case 'h': case 'H':
                suit = 2;
                break;
            case 's': case 'S':
                suit = 3;
                break;
            default:                            /* 如果用户输入的花色不在罗列的4 个中，则说明用户输入了一个非法的牌面，因此设置变量bad_card为true */
                bad_card = true;
        }


        /*
         * 对用户该次抽取的牌进行分析检查
         * 如果为"Bad card"或"Duplicate card"，则输出错误提示信息，并忽略到此次抽取的牌，直接进行下一次循环让用户重新抽取
         * 如果用户抽取的牌是合理的，则
         * 1. 分别对两个全局数组变量的相应元素自增1：rank和suit代表元素下标；num_in_rank[rank]和num_in_suit[suit]代表本轮游戏到目前为止该等级和花色的牌出现的次数
         * 2. 将函数内部用来检查重复牌的数组的相应元素设置为true：card_exists[rank][suit]代表本轮游戏本次抽牌所抽中的牌（等级和花色的组合）
         * 3. 将计数器自增1：card_read代表本轮游戏目前为止已经进行了几次抽牌，按照要求一轮游戏有且仅有5次抽牌
         */
        if (bad_card)
        {
            printf("Bad card; ignored.\n");
        }
        else if (card_exists[rank][suit])
        {
            printf("Duplicate card; ignored.\n");
        }
        else
        {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

