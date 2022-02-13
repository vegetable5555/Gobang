#include"Settingpage.h"
using namespace std;
//显示页面元素函数
void Settingpage::DrawCharacter()
{
	//显示背景图片
	DrawBK();

	settextcolor(WHITE);                     //设置字体颜色
	setbkmode(TRANSPARENT);                  //去除字体的黑框 
	settextstyle(50, 0, L"华文新魏");        //设置字体类型及大小

	//显示各项选择
	outtextxy(190, 50, L"游戏背景");
	outtextxy(190, 150, L"背景音乐");
	outtextxy(240, 250, L"返回");
}
//鼠标操作函数
void Settingpage::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	//清空鼠标信息缓存
	FlushMouseMsgBuffer();

	while (1)
	{
		while (MouseHit())      //当鼠标单击时
		{
			//获取鼠标信息
			m = GetMouseMsg();
			if ((m.x >= 190 && m.x <= 390) && (m.y >= 50 && m.y <= 100))   //设置背景
			{
				if (m.uMsg == WM_LBUTTONDOWN)      //单击鼠标左键，下同
				{
					PageNum = 6;
					return;
				}
			}
			else if ((m.x >= 240 && m.x <= 340) && (m.y >= 250 && m.y <= 300))   //返回
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 390) && (m.y >= 150 && m.y <= 200))    //设置音乐
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 7;
					return;
				}
			}
		}
	}
}