#include"Gamepage.h"
#include"Page.h"
int Judge(int chess[27][27], int flag, int x, int y)
{
	int R, L, L1, L2;
	L = 0; R = 0; L1 = 0; L2 = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x - i][y] == flag)
			L++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x][y + i] == flag)
			L++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x][y + i] == flag)
			R++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x][y - i] == flag)
			R++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x - i][y - i] == flag)
			L1++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x + i][y + i] == flag)
			L1++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x + i][y - i] == flag)
			L2++;
		else break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (chess[x - i][y + i] == flag)
			L2++;
		else break;
	}
	if (L == 4 || L1 == 4 || L2 == 4 || R == 4)
		return 1;
	return 0;

}
void Setlevel(Player* p)
{
	if (p->Getmark() >= 0 && p->Getmark() <= 10)
		p->SetLevel('C');
	else if (p->Getmark() >= 10 && p->Getmark() <= 30)
		p->SetLevel('B');
	else if (p->Getmark() > 30)
		p->SetLevel('A');
}
void GamePage::DrawChessBoard()
{
	setlinecolor(BLACK);
	for (int i = 10; i <= 530; i += 20)
	{
		line(10, i, 530, i);//划横线   x1,y1,x2,y2
		line(i, 10, i, 530);//画竖线
	}
	/*加粗棋盘*/
	setlinestyle(PS_SOLID, 3);
	line(10, 10, 10, 530);
	line(10, 530, 530, 530);
	line(10, 10, 530, 10);
	line(530, 10, 530, 530);
	fillcircle(270, 270, 1);
	fillcircle(270, 270, 2);/*x,y,r*/
}
void GamePage::DrawCharacter()
{
	setbkmode(TRANSPARENT);//去除颜色的黑框 
	settextcolor(BLACK);/*字体颜色*/
	settextstyle(40, 0, L"华文新魏");
	outtextxy(900, 10, L"返回主页面");
	outtextxy(940, 60, L"重新开始");
}
void GamePage::Mousehit()//玩游戏
{//鼠标技术
	int x, y, i, j;
	int chess[27][27] = { 0 };//save the location of chess
	MOUSEMSG m;
	unsigned long long r = 1;
	FlushMouseMsgBuffer();//清空鼠标信息缓存

	while (1)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if (m.x >= 5 && m.x <= 540 && m.y >= 5 && m.y <= 540)
			{
				if (m.uMsg == WM_LBUTTONDOWN && !win)
				{
					x = m.x % 20;
					if (x <= 10)
						m.x = (m.x - x) + 10;
					else
						m.x = (m.x / 20) * 20 + 10;
					y = m.y % 20;
					if (y <= 10)
						m.y = (m.y - y) + 10;
					else
						m.y = (m.y / 20) * 20 + 10;
					i = m.x / 20;
					j = m.y / 20;

					if (r == 1 && !chess[i][j])
					{
						r = 3 - r;
						setlinecolor(BLACK);
						setfillcolor(BLACK);
						fillcircle(m.x, m.y, 8);
						chess[i][j] = 1;
						//判断输赢
						if (Judge(chess, 1, i, j))
						{
							settextcolor(RED);
							settextstyle(50, 0, L"华文新魏");
							setbkmode(TRANSPARENT);
							outtextxy(200, 200, L"黑棋胜");
							win = 1;

						}
					}
					else if (r == 2 && !chess[i][j])
					{
						r = 3 - r;
						setlinecolor(WHITE);
						setfillcolor(WHITE);
						fillcircle(m.x, m.y, 8);
						chess[i][j] = 2;
						if (Judge(chess, 2, i, j))
						{
							settextcolor(RED);
							settextstyle(50, 0, L"华文新魏");
							setbkmode(TRANSPARENT);
							outtextxy(200, 200, L"白棋胜");
							win = 2;

						}
					}
				}
			}
			else if (m.x >= 900 && m.x <= 1100 && m.y >= 10 && m.y <= 50)
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if (m.x >= 940 && m.x <= 1140 && m.y >= 60 && m.y <= 100)
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
void  GamePage::GameClean()
{
	if (win)
	{
		switch (win)
		{
		case 1:
		{switch (int(m_p1->GetLevel()) - int(m_p2->GetLevel()))
		{
		case -2:
		{int mark = m_p1->Getmark();
		m_p1->SetMark(mark + 1);
		break; }
		case -1:
		{int mark = m_p1->Getmark();
		m_p1->SetMark(mark + 2);
		break; }
		case 0:
		{int mark = m_p1->Getmark();
		m_p1->SetMark(mark + 3);
		break; }
		case 1:
		{int mark = m_p1->Getmark();
		m_p1->SetMark(mark + 4);
		break; }
		case 2:
		{int mark = m_p1->Getmark();
		m_p1->SetMark(mark + 5);
		break; }
		}
		break; }
		case 2:
		{switch (int(m_p2->GetLevel()) - int(m_p1->GetLevel()))
		{
		case -2:
		{int mark = m_p2->Getmark();
		m_p2->SetMark(mark + 1);
		break; }
		case -1:
		{int mark = m_p2->Getmark();
		m_p2->SetMark(mark + 2);
		break; }
		case 0:
		{int mark = m_p2->Getmark();
		m_p2->SetMark(mark + 3);
		break; }
		case 1:
		{int mark = m_p2->Getmark();
		m_p2->SetMark(mark + 4);
		break; }
		case 2:
		{int mark = m_p2->Getmark();
		m_p2->SetMark(mark + 5);
		break; }
		}
		break;
		}
		}
		Setlevel(m_p1);
		Setlevel(m_p2);
	}
	else return;
}