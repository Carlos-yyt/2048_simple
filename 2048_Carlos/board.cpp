#include "board.h"
board::board()
{
}

board::~board()
{
}

int board::checkBoard()
{
	int maxCell_pur = 0;	//当前单个格子最大值
	int score_pur = 0;		//当前总得分
	int BlankCell = 16;		//空格子的个数

	step++;

	//遍历当前棋盘
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (BOARD[i][j] != 0)
			{
				score_pur += BOARD[i][j];
				if (BOARD[i][j] > maxCell_pur)
				{
					maxCell_pur = BOARD[i][j];
				}
				BlankCell--;
			}
		}
	}

	//更新玩家得分数据
	maxCell = maxCell_pur;
	score = score_pur;

	//判断游戏状态（输、赢、继续）
	if (maxCell == MAX_NUM)
	{
		return WIN;
	}
	else if (BlankCell == 0)
	{
		return LOSS;//没有2048，又满格了，那就是输了
	}


	return CONTINUE;
}

inline void board::lineMove(int * line)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int fullZero = 1;//剩下的全是零

	//消除空格 归并相同项
	for (i = 1; i < 4; i++)
	{
		fullZero = 1;
		for (k = i; k < 4; k++)
		{
			if (line[k] != 0)
			{
				fullZero = 0;
			}
		}
		if (fullZero)
		{
			return ;//全是零
		}
		if (line[i - 1] == line[i] && line[i] != 0)//归并相同的 0不归并
		{
			line[i - 1] = line[i] + line[i - 1];
			line[i] = 0;
		}

		if (line[i - 1] == 0)//消除空格
		{
			for (j = i - 1; j < 3 ; j++)
			{
				line[j] = line[j + 1];
			}
			line[3] = 0;//最后一位补0
			i-=2;//消除完空格之后 要再来一轮
		}
	}
	return ;//不全是零
}

void board::leftMove()
{
	int i = 0;
	int j = 0;
	int line[4] = { 0 };

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			line[j] = BOARD[i][j];
		}
		lineMove(line);
		for (j = 0; j < 4; j++)
		{
			BOARD[i][j] = line[j];
		}
	}
}

void board::rightMove()
{
	int i = 0;
	int j = 0;
	int line[4] = { 0 };

	for (i = 0; i < 4; i++)
	{
		for (j = 3; j >= 0; j--)
		{
			line[3 - j] = BOARD[i][j];
		}
		lineMove(line);
		for (j = 3; j >= 0; j--)
		{
			BOARD[i][j] = line[3 - j];
		}
	}
}

void board::upMove()
{
	int i = 0;
	int j = 0;
	int line[4] = { 0 };

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			line[i] = BOARD[i][j];
		}
		lineMove(line);
		for (i = 0; i < 4; i++)
		{
			BOARD[i][j] = line[i];
		}
		
	}
}

void board::downMove()
{
	int i = 0;
	int j = 0;
	int line[4] = { 0 };

	for (j = 0; j < 4; j++)
	{
		for (i = 3; i >= 0; i--)
		{
			line[3 - i] = BOARD[i][j];
		}
		lineMove(line);
		for (i = 3; i >= 0; i--)
		{
			BOARD[i][j] = line[3 - i];
		}
	}
}

void board::Usermove(int choice)
{
	switch (choice)
	{
	case 1:upMove(); break;
	case 2:downMove(); break;
	case 3:leftMove(); break;
	case 4:rightMove(); break;
	default:
		break;
	}
}

void board::showBoard()
{
	system("CLS");//清屏
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", BOARD[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	printf("当前单格最大值：%d\n", maxCell);
	printf("当前总分：%d\n\n", score);
	printf("请使用小写英文wsad(对应上下左右)控制游戏。\n");
}

void board::newNumber()
{
	int x = 0;
	int y = 0;
	int newNumber = 0;
	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (BOARD[x][y] != 0);
	
	while (1)
	{
		newNumber = (rand() % 5) / 2;
		if (newNumber != 0 && newNumber!=1)
		{
			BOARD[x][y] = newNumber;
			break;
		}
	}
}
