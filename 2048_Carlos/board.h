#pragma once
#include "define.h"

class board
{
public:
	board();
	~board();

	int checkBoard();//判断棋局，更新分数栏，顺便判断游戏状态（输、赢、继续）
	
	inline void lineMove(int *line);	//将一条线上的数字滑动到一段 并且按照规则归并
	void leftMove();	//左滑
	void rightMove();	//右滑
	void upMove();		//上滑
	void downMove();	//下滑
	void Usermove(int choice);	//用户滑动一次

	void showBoard();//显示棋盘 和 分数栏

	void newNumber();
private:
	int BOARD[4][4] = { 0 };		//游戏棋盘

	int score = 0;				//分数	（是所有棋格分值之和）
	int maxCell = 0;			//单个格子最大值
	int step = 0;				//游戏步数

	int score_history = 0;		//历史 分数 最高分
	int maxCell_history = 0;	//历史 单个格子最大值 最高分
};