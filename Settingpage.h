#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
using namespace std;
//设置页面类
class Settingpage :public Page
{
public:
	//构造函数
	Settingpage(IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;

	}

	//显示页面元素函数
	void DrawCharacter();

	//鼠标操作函数
	void Mousehit();
};
