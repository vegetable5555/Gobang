#include"Backgroundmusicpage.h"
void Backgroundmusic::DrawCharacter()
{
	//显示背景图片
	DrawBK();

	settextcolor(WHITE);                     //设置字体颜色
	setbkmode(TRANSPARENT);                  //去除字体的黑框 
	settextstyle(30, 0, L"华文新魏");        //设置字体类型及大小

	//显示各项选择
	outtextxy(210, 40, L"优雅古调");
	outtextxy(165, 90, L"夜空中最亮的星");
	outtextxy(240, 140, L"演员");
	outtextxy(240, 190, L"大鱼");
	outtextxy(210, 240, L"关闭音乐");
	settextstyle(50, 0, L"华文新魏");        //更新字体大小
	outtextxy(10, 280, L"返回");
}
void Backgroundmusic::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	//清空鼠标信息缓存
	FlushMouseMsgBuffer();
	while (1)
	{
		while (MouseHit())          //当鼠标单击时
		{
			m = GetMouseMsg();      //获取鼠标信息
			if ((m.x >= 210 && m.x <= 330) && (m.y >= 40 && m.y <= 70))
			{
				if (m.uMsg == WM_LBUTTONDOWN)                                   //单击左键
				{
					mciSendString(L"close music", 0, 0, 0);                     //关闭原始音乐
					mciSendString(L"open 优雅古调.mp3 alias music", 0, 0, 0);   //打开新音乐
					mciSendString(L"play music repeat", 0, 0, 0);               //设置重复播放
					PageNum = 5;                                                //返回设置页面
					return;                                                     //下同
				}
			}
			else if ((m.x >= 165 && m.x <= 375) && (m.y >= 90 && m.y <= 120))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					mciSendString(L"open 夜空中最亮的星.mp3 alias music", 0, 0, 0);
					mciSendString(L"play music repeat", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 240 && m.x <= 300) && (m.y >= 140 && m.y <= 170))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					mciSendString(L"open 演员.mp3 alias music", 0, 0, 0);
					mciSendString(L"play music repeat", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 240 && m.x <= 300) && (m.y >= 190 && m.y <= 220))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					mciSendString(L"open 大鱼.mp3 alias music", 0, 0, 0);
					mciSendString(L"play music repeat", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 210 && m.x <= 330) && (m.y >= 240 && m.y <= 270))//关闭音乐
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//直接返回设置页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 5;
					return;
				}
			}
		}
	}
}