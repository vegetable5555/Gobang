#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Textbox.h"
#include"player.h"
#include"Page.h"
using namespace std;
//注册页面类
class Signuppage :public Page
{
public:
	//构造函数
	Signuppage(IMAGE bkimage, Player* playerlist[100], int* size) :Page(bkimage)
	{
		m_bkimage = bkimage;
		m_playerlist = playerlist;
		m_size = size;
		m_judge = 0;
	}

	//显示页面元素函数
	void DrawCharacter();

	//键盘输入操作函数
	void Input();

	//鼠标操作函数
	void Mousehit();

protected:
	Player** m_playerlist;
	int* m_size;
	int m_judge;
};
