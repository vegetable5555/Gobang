#include"Textbox.h"
using namespace std;
//构造函数
TextBox::TextBox(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}
//绘制文本框函数
void TextBox::Draw()
{
	//设置文本框颜色
	setlinecolor(BLACK);
	setfillcolor(BLACK);

	//设置文本框位置及大小
	fillrectangle(m_x1, m_y1, m_x2, m_y2);
}
