#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
using namespace std;
//基类页面
class Page
{
public:
	static int PageNum;
	//构造函数
	Page(IMAGE bkimage)
	{
		m_bkimage = bkimage;
	}

	//显示背景图片
	void DrawBK();

	//显示页面元素和鼠标操作的纯虚函数
	virtual void DrawCharacter() = 0;
	virtual void Mousehit() = 0;

protected:
	IMAGE m_bkimage;

};