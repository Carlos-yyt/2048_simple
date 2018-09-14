/*
2048小游戏	C++实现
*/

#include "board.h"

int main() {
	board Board;
	Board.showBoard();
	int GameState = CONTINUE;	//控制游戏是否结束
	char keyboard;				//键盘状况

	//先放两个数字在界面上
	Board.newNumber();
	Board.newNumber();
	Board.showBoard();
	while (GameState == CONTINUE)
	{
		if (_kbhit())
		{
			keyboard = _getch();
			switch (keyboard)
			{
			case 'w':Board.Usermove(1); break;
			case 's':Board.Usermove(2); break;
			case 'a':Board.Usermove(3); break;
			case 'd':Board.Usermove(4); break;
			case 'e':GameState = PASS; break;
			default:
				printf("\n请看看程序说明，关掉重来吧。\n");
				GameState = PASS;
				system("pause");
				break;
			}

			if (GameState==PASS)
			{
				break;
			}

			Board.newNumber();
			GameState = Board.checkBoard();
			Board.showBoard();
		}
	}

	if (GameState == WIN)
	{
		printf("\n\n2048！你赢了！\n");
	}
	else if (GameState == LOSS)
	{
		printf("\n\n胜败乃兵家常事！不要气馁哦~\n");
	}
	else if (GameState==PASS)
	{
		printf("\n欢迎再来玩~\n");
	}

	system("pause");
}