#include"Backgroundpage.h"
//获取背景图片地址
IMAGE* Background::Getm_GBG()
{
	return m_GBG;
}
//显示页面元素函数
void Background::DrawCharacter()
{
	//显示背景图片
	DrawBK();

	settextcolor(WHITE);                     //设置字体颜色
	setbkmode(TRANSPARENT);                  //去除字体的黑框 
	settextstyle(30, 0, L"华文新魏");        //设置字体类型及大小

	//显示各选择项
	outtextxy(190, 40, L"蓝色幻想");
	outtextxy(190, 90, L"无人生还");
	outtextxy(190, 140, L"临江赋咏");
	outtextxy(190, 190, L"泼墨山水");
	outtextxy(190, 240, L"科技风暴");
	settextstyle(50, 0, L"华文新魏");         //更新字体大小
	outtextxy(10, 280, L"返回");
}
//鼠标操作函数
void Background::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	//清空鼠标信息缓存
	FlushMouseMsgBuffer();
	while (1)
	{
		while (MouseHit())      //当鼠标单击时
		{
			m = GetMouseMsg();  //获取鼠标信息
			if ((m.x >= 190 && m.x <= 310) && (m.y >= 40 && m.y <= 70))
			{
				if (m.uMsg == WM_LBUTTONDOWN)                //单击左键
				{
					loadimage(m_GBG, L"蓝色幻想.jpg");       //加载对应背景图片
					PageNum = 5;                             //返回设置页面
					return;                                  //下同
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 90 && m.y <= 120))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"无人生还.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 140 && m.y <= 170))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"临江赋咏.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 190 && m.y <= 220))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"泼墨山水.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 240 && m.y <= 270))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"科技风暴.jpg");
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