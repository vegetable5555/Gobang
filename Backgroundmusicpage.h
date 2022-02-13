#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
//设置音乐页面
class Backgroundmusic :public Page
{
public:
	//构造函数
	Backgroundmusic(IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;
	}

	//显示本页面元素函数
	void DrawCharacter();

	//鼠标操作函数
	void Mousehit();
}; 
