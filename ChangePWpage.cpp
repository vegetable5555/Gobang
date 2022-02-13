#include"ChangePWPage.h"
void ChangePWPage::DrawCharacter()
{	//�ı������
	TextBox userID(240, 85, 380, 105);
	TextBox password(240, 115, 380, 135);
	TextBox npassword1(240, 145, 380, 165);
	TextBox npassword2(240, 175, 380, 195);
	settextcolor(WHITE);                     //����������ɫ
	setbkmode(TRANSPARENT);                  //ȥ������ĺڿ� 
	settextstyle(50, 0, L"������κ");
	outtextxy(210, 30, L"�޸�����");
	settextstyle(20, 0, L"������κ");
	outtextxy(170, 85, L"�û�����");
	outtextxy(170, 115, L"���룺");
	outtextxy(150, 145, L"�����룺");
	outtextxy(110, 175, L"ȷ�������룺");
	outtextxy(10, 10, L" ��ESC��������ҳ��");
	outtextxy(10, 30, L"�����½����޸�ҳ��");
	//�û��������������
	userID.Draw();
	password.Draw();
	npassword1.Draw();
	npassword2.Draw();
}
void ChangePWPage::Input()
{   //��ʱ�洢����
	string Id;
	string password;
	string npassword1;
	string npassword2;
	char key;
	/*����Ȧ���������λ��*/
	setfillcolor(WHITE);
	fillcircle(390, 95, 8);
	for (int i = 0; i < 4; i++)
	{	//�����λ����
		int Ox, Oy;
		Ox = 240;
		Oy = 85 + i * 30;
		while (1)
		{
			key = _getch();
			//���в���
			if (key == 13)
			{
				if (i != 3)
				{
					setfillcolor(WHITE);
					fillcircle(390, 95 + 30 * (i + 1), 8);
				}
				break;
			}
			//Esc��
			else if (key == 27)
			{
				settextstyle(20, 0, L"������κ");
				outtextxy(20, 60, L"���أ�");
				outtextxy(20, 90, L"���䣿");
				outtextxy(15, 120, L"��������꣩");
				m_judge = 2;
				return;
			}
			//ɾ��
			else if (key == 8)
			{
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(Ox - 10, Oy, Ox, Oy + 20);

				//ɾȥ��һ���ַ�
				if (i == 0)
				{
					Id.erase(Id.size() - 1);
				}
				else if (i == 1)
				{
					password.erase(password.size() - 1);
				}
				else if (i == 2)
				{
					npassword1.erase(npassword1.size() - 1);
				}
				else
				{
					npassword2.erase(npassword2.size() - 1);
				}
				Ox -= 10;
			}
			//�������
			else
			{
				outtextxy(Ox, Oy, key);

				//���û����������Ĵ���
				if (i == 0)
				{
					Id += key;
				}
				else if (i == 1)
				{
					password += key;
				}
				else if (i == 2)
				{
					npassword1 += key;
				}
				else
				{
					npassword2 += key;
				}
				Ox += 10;
			}
		}
	}
	int d;//��ʱ�洢��Ҫ�޸ĵ�λ��
	//�ж������޸ĵ������Ƿ���ͬ
	if (npassword1 == npassword2)
	{
		m_same = 1;
	}
	//�ж��˺ź;������Ƿ��Ӧ
	for (int i = 0; i < m_size; i++)
	{
		if (m_PL[i]->GetId() == Id && m_PL[i]->Getpassword() == password && m_same)
		{
			d = i;
			m_judge = 1;
			break;
		}
	}
	if (m_judge && m_same)
	{
		m_PL[d]->SetPassword(npassword1);
		settextstyle(50, 0, L"������κ");
		outtextxy(190, 280, L"�޸ĳɹ�");
		outtextxy(10, 280, L"����");
		return;
	}
	else if (!m_judge)
	{
		settextstyle(30, 0, L"������κ");
		outtextxy(190, 280, L"�˺Ż��������");
		settextstyle(50, 0, L"������κ");
		outtextxy(10, 280, L"����");
		outtextxy(500, 280, L"����");
		return;
	}
	else if (!m_same)
	{
		settextstyle(30, 0, L"������κ");
		outtextxy(190, 280, L"���������벻��");
		settextstyle(50, 0, L"������κ");
		outtextxy(10, 280, L"����");
		outtextxy(500, 280, L"����");
		return;
	}
}
void ChangePWPage::Mousehit()
{//���������Ϣ
	MOUSEMSG m;
	FlushMouseMsgBuffer();//��������Ϣ����
	while (1)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if ((m.x >= 500 && m.x <= 600) && (m.y >= 280 && m.y <= 320) && (!(m_judge && m_same)))//������Ϻ����½����¼ҳ�����
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 9;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//������Ϻ󣬷�����ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 60 && m.y <= 80))//��Esc���󣬷�����ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 90 && m.y <= 110))//��Esc�������½����¼ҳ�����
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