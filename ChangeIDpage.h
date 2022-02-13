#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
#include"Page.h"
//ÐÞ¸ÄÒ³Ãæ
class ChangeIDPage :public Page
{
public:
	ChangeIDPage(IMAGE bkimage, Player* playerlist[100], int size) :Page(bkimage)
	{
		m_bkimage = bkimage;
		m_PL = playerlist;
		m_size = size;
		m_judge = 0;
		m_same = 0;
	}
	void DrawCharacter();
	void Input();
	void Mousehit();
protected:
	Player** m_PL;
	int m_size;
	int m_judge;
	int m_same;
};