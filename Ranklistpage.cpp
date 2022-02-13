#include"Ranklistpage.h"
#include"Page.h"
void RankListPage::DrawCharacter()
{
	settextstyle(50, 0, L"������κ");//������������
	setbkmode(TRANSPARENT);//ȥ����ɫ�ĺڿ� 
	settextcolor(BLACK);/*������ɫ*/
	outtextxy(250, 10, L"���а�");
	settextstyle(40, 0, L"������κ");
	outtextxy(100 - 20, 70, L"����");
	outtextxy(250 - 20, 70, L"�˺�");
	outtextxy(400 - 20, 70, L"�ȼ�");
	outtextxy(550 - 20, 70, L"����");
	outtextxy(900, 10, L"������ҳ��");
}
void RankListPage::Mousehit()
{
	MOUSEMSG m;
	FlushMouseMsgBuffer();//��������Ϣ����
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
		settextstyle(30, 0, L"������κ");
		TCHAR t[10];
		//int ת Tchar
		_itow_s(i + 1, t, 10);
		outtextxy(100, 120 + 45 * i, t);
		/*����ַ����*/
		for (int j = 0; j < m_PL[i]->GetId().size(); j++)
		{
			outtextxy(190 + 15 * j, 120 + 45 * i, m_PL[i]->GetId()[j]);
		}
		outtextxy(400, 120 + 45 * i, m_PL[i]->GetLevel());
		_itow_s(m_PL[i]->Getmark(), t, 10);
		outtextxy(540, 120 + 45 * i, t);
	}
}
