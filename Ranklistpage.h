#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
#include"Page.h"
//≈≈––∞Ò“≥√Ê
class RankListPage :public Page
{
public:
	RankListPage(IMAGE bkimage, Player* PL[100], int size) :Page(bkimage)
	{
		m_PL = PL;
		m_size = size;
	}
	void DrawCharacter();
	void Mousehit();
	void Rank();
	void ShowRank();
private:
	Player** m_PL;
	int m_size;
};
