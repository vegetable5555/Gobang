#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
#include"Page.h"
using namespace std;
//”Œœ∑“≥√Ê
class GamePage :public Page
{
public:
	GamePage(IMAGE bkimage, Player* p1, Player* p2) :Page(bkimage)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	void DrawChessBoard();
	void DrawCharacter();
	void Mousehit();
	void GameClean();
private:
	Player* m_p1, * m_p2;
	int win;
};
void Setlevel(Player* p);
int Judge(int chess[27][27], int flag, int x, int y);
