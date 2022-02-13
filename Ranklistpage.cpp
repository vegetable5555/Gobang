#include"Ranklistpage.h"
#include"Page.h"
void RankListPage::DrawCharacter()
{
	settextstyle(50, 0, L"华文新魏");//设置字体类型
	setbkmode(TRANSPARENT);//去除颜色的黑框 
	settextcolor(BLACK);/*字体颜色*/
	outtextxy(250, 10, L"排行榜");
	settextstyle(40, 0, L"华文新魏");
	outtextxy(100 - 20, 70, L"排名");
	outtextxy(250 - 20, 70, L"账号");
	outtextxy(400 - 20, 70, L"等级");
	outtextxy(550 - 20, 70, L"分数");
	outtextxy(900, 10, L"返回主页面");
}
void RankListPage::Mousehit()
{
	MOUSEMSG m;
	FlushMouseMsgBuffer();//清空鼠标信息缓存
	while (1)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if ((m.x >= 900 && m.x <= 1100) && (m.y >= 10 && m.y <= 40))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
				else
				{
					if (m.uMsg == WM_LBUTTONDOWN)
					{
						PageNum = 1;
						return;
					}
				}
			}

		}

	}
}
void RankListPage::Rank()
{
	for (int i = 0; i < m_size - 1; i++)
	{
		for (int j = 0; j < m_size - i - 1; j++)
			if (m_PL[j]->Getmark() < m_PL[j + 1]->Getmark())
			{
				Player* tp = m_PL[j];
				m_PL[j] = m_PL[j + 1];
				m_PL[j + 1] = tp;
			}
	}
}
void RankListPage::ShowRank()
{
	for (int i = 0; i < m_size; i++)
	{
		settextstyle(30, 0, L"华文新魏");
		TCHAR t[10];
		//int 转 Tchar
		_itow_s(i + 1, t, 10);
		outtextxy(100, 120 + 45 * i, t);
		/*逐个字符输出*/
		for (int j = 0; j < m_PL[i]->GetId().size(); j++)
		{
			outtextxy(190 + 15 * j, 120 + 45 * i, m_PL[i]->GetId()[j]);
		}
		outtextxy(400, 120 + 45 * i, m_PL[i]->GetLevel());
		_itow_s(m_PL[i]->Getmark(), t, 10);
		outtextxy(540, 120 + 45 * i, t);
	}
}
