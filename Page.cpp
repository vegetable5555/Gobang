#include"Page.h"
//初始化静态成员PageNum
int Page::PageNum = 0;
//显示背景图片
void Page::DrawBK()
{
	//获取照片的尺寸
	int width = m_bkimage.getwidth();
	int height = m_bkimage.getheight();
	//调节窗口大小
	initgraph(width, height);
	//显示图片
	putimage(0, 0, &m_bkimage);
}