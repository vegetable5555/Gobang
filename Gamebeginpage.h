#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
#include"Page.h"
//初始页面;
class GameBeginPage :public Page
{
public:
	//构造函数
	GameBeginPage(IMAGE bkimage) :Page(bkimage)
	{}

	//显示页面元素函数
	void DrawCharacter();

	//鼠标操作函数
	void Mousehit();
};