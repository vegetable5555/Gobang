#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Textbox.h"
#include"Player.h"
#include"Page.h"
using namespace std;
//登录页面类
class Loginpage :public Page
{
public:
	//构造函数
	Loginpage(IMAGE bkimage, Player* playerlist[100], int size) :Page(bkimage)
	{
		m_bkimage = bkimage;         //设置本页背景
		m_playerlist = playerlist;   //传入玩家数组
		m_size = size;               //传入目前玩家数量
		m_judge = 0;                 //页面各接口开关
	}
	//显示本页面元素函数
	void DrawCharacter();

	//键盘输入操作函数
	void Input(int* np1, int* np2);

	//鼠标操作函数
	void Mousehit();

protected:
	Player** m_playerlist;
	int m_size;
	int m_judge;
};
