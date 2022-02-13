#include"Gamebeginpage.h"
#include"Page.h"
void GameBeginPage::DrawCharacter()
{
	settextstyle(50, 0, L"华文新魏");     //设置字体类型及大小
	setbkmode(TRANSPARENT);               //去除颜色的黑框 
	settextcolor(WHITE);                  //设置字体颜色

	//显示各项选择
	outtextxy(230, 30, L"登录");
	outtextxy(230, 100, L"注册");
	outtextxy(210, 180, L"排行榜");
	outtextxy(230, 260, L"设置");

	settextstyle(30, 0, L"华文新魏");      //更新字体大小

	outtextxy(10, 10, L"修改账号");
	outtextxy(10, 50, L"修改密码");
}
void GameBeginPage::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	FlushMouseMsgBuffer();//清空鼠标信息缓存
	while (1)
	{
		while (MouseHit())          //当鼠标单击时
		{
			m = GetMouseMsg();      //获取鼠标信息
			if ((m.x >= 230 && m.x <= 320) && (m.y >= 30 && m.y <= 75))       //跳转至登录页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)            //单击左键，下同
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 230 && m.x <= 320) && (m.y >= 100 && m.y <= 145))     //跳转至注册页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 3;
					return;
				}
			}
			else if (((m.x >= 230 && m.x <= 320) && (m.y >= 180 && m.y <= 225)))    //跳转至排行榜页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 4;
					return;
				}
			}
			else if (((m.x >= 230 && m.x <= 320) && (m.y >= 260 && m.y <= 305)))     //跳转至设置页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 5;
					return;
				}
			}
			else if (((m.x >= 10 && m.x <= 130) && (m.y >= 10 && m.y <= 40)))         //跳转至修改账号页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 8;
					return;
				}
			}
			else if (((m.x >= 10 && m.x <= 130) && (m.y >= 50 && m.y <= 80)))         //跳转至修改密码页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 9;
					return;
				}
			}
		}

	}
}