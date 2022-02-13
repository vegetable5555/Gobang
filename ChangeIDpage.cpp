#include"ChangeIDPage.h"
void ChangeIDPage::DrawCharacter()
{	//文本框对象
	TextBox userID(240, 85, 380, 105);
	TextBox password(240, 115, 380, 135);
	TextBox newuserID(240, 145, 380, 165);
	settextcolor(WHITE);                     //设置字体颜色
	setbkmode(TRANSPARENT);                  //去除字体的黑框 
	settextstyle(50, 0, L"华文新魏");
	outtextxy(210, 30, L"修改账号");
	settextstyle(20, 0, L"华文新魏");
	outtextxy(170, 85, L"用户名：");
	outtextxy(170, 115, L"密码：");
	outtextxy(150, 145, L"新用户名：");
	outtextxy(10, 10, L" 按ESC键返回主页面");
	outtextxy(10, 30, L"或重新进入修改页面");
	//用户名和密码输入框
	userID.Draw();
	password.Draw();
	newuserID.Draw();
}
void ChangeIDPage::Input()
{   //即时存储数据
	string Id;
	string password;
	string nId;
	char key;
	/*画白圈，提醒输出位置*/
	setfillcolor(WHITE);
	fillcircle(390, 95, 8);
	for (int i = 0; i < 3; i++)
	{	//输出定位坐标
		int Ox, Oy;
		Ox = 240;
		Oy = 85 + i * 30;
		while (1)
		{
			key = _getch();
			//换行操作
			if (key == 13)
			{
				if (i != 2)
				{
					setfillcolor(WHITE);
					fillcircle(390, 95 + 30 * (i + 1), 8);
				}
				break;
			}
			//Esc键
			else if (key == 27)
			{
				settextstyle(20, 0, L"华文新魏");
				outtextxy(20, 60, L"返回？");
				outtextxy(20, 90, L"重输？");
				outtextxy(15, 120, L"（单击鼠标）");
				m_judge = 2;
				return;
			}
			//删除
			else if (key == 8)
			{
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(Ox - 10, Oy, Ox, Oy + 20);

				//删去上一个字符
				if (i == 0)
				{
					Id.erase(Id.size() - 1);
				}
				else if (i == 1)
				{
					password.erase(password.size() - 1);
				}
				else
				{
					nId.erase(nId.size() - 1);
				}
				Ox -= 10;
			}
			//输入操作
			else
			{
				outtextxy(Ox, Oy, key);

				//将用户的输入存进寄存器
				if (i == 0)
				{
					Id += key;
				}
				else if (i == 1)
				{
					password += key;
				}
				else
				{
					nId += key;
				}
				Ox += 10;
			}
		}
	}
	int d;//暂时存储需要修改的位置
	for (int i = 0; i < m_size; i++)
	{
		if (m_PL[i]->GetId() == Id && m_PL[i]->Getpassword() == password && !m_same)
		{
			d = i;
			m_judge = 1;
			break;
		}
	}
	for (int i = 0; i < m_size; i++)
	{
		if (m_PL[i]->GetId() == nId)
		{
			m_same = 1;
			break;
		}
	}
	if (m_judge && !m_same)
	{
		m_PL[d]->SetId(nId);
		settextstyle(50, 0, L"华文新魏");
		outtextxy(190, 280, L"修改成功");
		outtextxy(10, 280, L"返回");
		return;
	}
	else if (!m_judge)
	{
		settextstyle(30, 0, L"华文新魏");
		outtextxy(190, 280, L"账号或密码错误");
		settextstyle(50, 0, L"华文新魏");
		outtextxy(10, 280, L"返回");
		outtextxy(500, 280, L"重输");
		return;
	}
	else if (m_same)
	{
		settextstyle(40, 0, L"华文新魏");
		outtextxy(190, 280, L"用户名已存在");
		settextstyle(50, 0, L"华文新魏");
		outtextxy(10, 280, L"返回");
		outtextxy(500, 280, L"重输");
		return;
	}
}
void ChangeIDPage::Mousehit()
{//鼠标坐标信息
	MOUSEMSG m;
	FlushMouseMsgBuffer();//清空鼠标信息缓存
	while (1)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if ((m.x >= 500 && m.x <= 600) && (m.y >= 280 && m.y <= 320) && !(m_judge && !m_same))//输入完毕后，重新进入登录页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 8;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//输入完毕后，返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 60 && m.y <= 80))//按Esc键后，返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 90 && m.y <= 110))//按Esc键后，重新进入登录页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 8;
					return;
				}
			}

		}
	}
}