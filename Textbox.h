#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
//文本框类
class TextBox
{
public:
	//构造函数
	TextBox(int x1, int y1, int x2, int y2);

	//绘制文本框
	void Draw();

private:
	//文本框坐标
	int m_x1, m_x2, m_y1, m_y2;
};
