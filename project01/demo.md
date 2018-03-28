## 纸牌游戏

每轮游戏中用户输入一手5张牌，每张牌都有花色和等级两个属性；程序读取用户输入的5张牌，然后将手中的牌分为下列中的某一类并输出结果：

* 同花顺（5张牌的等级连续，花色相同）
* 四张  （4张牌的等级相同）
* 葫芦  （5张牌中有三张牌为同一等级，另外两张牌为另一种等级）
* 同花  （5张牌的花色相同）
* 顺子  （5张牌的等级连续）
* 三张  （3张牌的等级相同）
* 两对  （2对牌的等级相同）
* 一对  （1对牌的等级相同）
* 其它  （除上述8种类型外的任意情况）

注意：

上述列出的9种情况按牌面有好到坏的顺序排列，如果一手牌可以分类成不止一种情况，程序将选择一种最好的情况输出。

如果用户**输入非法牌**（*一张牌的花色或等级不在规定范围内*）或者**输入同一张牌两次**（*用户两次输入的牌的花色和等级都相同*），程序输出错误提示信息并将此次输入的牌面忽略掉，然后要求用户输入另外一张牌；如果用户输入为0而不是一张牌，则程序终止。

* 牌有4 种花色：方块、梅花、红桃、黑桃
* 牌有13种等级：2、3、4、5、6、7、8、9、10、J、Q、K、A
* 游戏规定不允许使用王牌，并假设A为最高等级

为了便于输入，把牌的等级和花色简化如下：

* 花色：c d h s
* 等级：2 3 4 5 6 7 8 9 t j q k a（用户输入时字母可以是大写或小写）


程序运行示例：

```
Enter a card: 2s
Enter a card: 5s
Enter a card: 4s
Enter a card: 3s
Enter a card: 6s
同花顺！

Enter a card: 8c
Enter a card: as
Enter a card: 8c
Duplicate card; ignored
Enter a card: 7c
Enter a card: ad
一对！

Enter a card: 6s
Enter a card: d2
Bad card; ignored
Enter a card: 2d
Enter a card: 9c
Enter a card: 4h
Enter a card: ts
其它！

Enter a card: 0
```

***

## Poker Game

Player enter a hand of five cards in each round, each card in the hand will have both a suit and a rank; The program will read a hand of five cards, then classify the hand into one of the following categories:

* `straight flush` : both a straight and a flush
* `four-of-a-kind` : four cards of the same rank
* `full horse`     : a three-of-a-kind and a pair
* `flush`          : five cards of the same suit
* `straight`       : five cards with consecutive ranks
* `three-of-a-kind`: three cards of the same rank
* `two pairs`      : two pairs of cards of the same rank
* `one pair`       : one pair of cards of the same rank
* `high card`      : any other hand

Notice:

categories are listed in order from best to worst, if a hand of cards falls into two or more categories, the program will choose the best one.

if the user **enters an illegal card**(*suit or rank is out of the range*) or **enter the same card twice**(*suit and rank are exactly the same as previous one*), the program will issue an error message and ignore the card, and then request another card; entering the number 0 instead of a card will cause the program to terminate.

* There are 4  kinds of suits: clubs, diamonds, hearts, spades
* Three are 13 kinds of ranks: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A
* we won't allow the use of jokers, and we'll assume that aces are high

For input purpose, we'll abbreviate suits and ranks as follows:

* suits: c d h s
* ranks: 2 3 4 5 6 7 8 9 t j q k a(letters may be either upper- or lower-case)

Program session demo:

```
Enter a card: 2s
Enter a card: 5s
Enter a card: 4s
Enter a card: 3s
Enter a card: 6s
straight flush!

Enter a card: 8c
Enter a card: as
Enter a card: 8c
Duplicate card; ignored
Enter a card: 7c
Enter a card: ad
One pair!

Enter a card: 6s
Enter a card: d2
Bad card; ignored
Enter a card: 2d
Enter a card: 9c
Enter a card: 4h
Enter a card: ts
High card!

Enter a card: 0
```

