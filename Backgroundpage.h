#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
//设置背景页面
class Background :public Page
{
public:
	//构造函数
	Background(IMAGE* GBG, IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;                //传入本页面的背景图片
		m_GBG = GBG;                        //传入背景图片地址
		loadimage(m_GBG, L"临江赋咏.jpg");  //设置默认背景
	}

	//显示本页面元素函数
	void DrawCharacter();

	//鼠标操作函数
	void Mousehit();

	//获取背景图片地址
	IMAGE* Getm_GBG();

protected:
	IMAGE* m_GBG;
};