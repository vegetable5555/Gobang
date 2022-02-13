#include"Loginpage.h"
using namespace std;
void Loginpage::DrawCharacter()
{
	//ʵ�����ı������
	TextBox username1(240, 85, 380, 105);
	TextBox password1(240, 115, 380, 135);
	TextBox username2(240, 200, 380, 220);
	TextBox password2(240, 230, 380, 250);

	//��ʾ����ͼƬ
	DrawBK();

	settextcolor(WHITE);                     //����������ɫ
	setbkmode(TRANSPARENT);                  //ȥ������ĺڿ� 
	settextstyle(50, 0, L"������κ");        //�����������ͼ���С

	//��ʾ����ѡ��
	outtextxy(210, 30, L"���һ");
	outtextxy(210, 150, L"��Ҷ�");

	settextstyle(20, 0, L"������κ");        //���������С

	outtextxy(170, 85, L"�û�����");
	outtextxy(170, 115, L"���룺");
	outtextxy(170, 200, L"�û�����");
	outtextxy(170, 230, L"���룺");
	outtextxy(10, 10, L" ��ESC��������ҳ��");
	outtextxy(10, 30, L"�����½����¼ҳ��");

	//��ʾ�û��������������
	username1.Draw();
	password1.Draw();
	username2.Draw();
	password2.Draw();
}
void Loginpage::Input(int* np1, int* np2)
{
	//�������
	Player P1;
	Player P2;

	//�û���������ļĴ���
	string _username1;
	string _password1;
	string _username2;
	string _password2;

	//�û��ļ�������
	char key1;

	//���һ����Ϣ����
	for (int i = 0; i < 2; i++)
	{
		//��������λ�����ڿ�
		setfillcolor(WHITE);
		fillcircle(390, 95, 8);

		//�����x��y����
		int key1_x = 240;
		int key1_y = 85 + i * 30;

		while (1)
		{
			//��ȡ�û�����
			key1 = _getch();

			//���в���
			if (key1 == 13)     //���س���
			{
				setfillcolor(WHITE);       //��������λ��
				fillcircle(390, 125, 8);
				break;
			}

			//Esc��
			else if (key1 == 27)
			{
				settextstyle(20, 0, L"������κ");
				outtextxy(20, 60, L"���أ�");
				outtextxy(20, 90, L"���䣿");
				outtextxy(15, 120, L"��������꣩");
				m_judge = 2;
				return;
			}

			//�������
			else if (key1 == 8)       //��Backspace��
			{
				//�˸�
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key1_x - 10, key1_y, key1_x, key1_y + 20);

				//ɾȥ��һ���ַ�
				if (i == 0)
				{
					_username1.erase(_username1.size() - 1);
				}
				else
				{
					_password1.erase(_password1.size() - 1);
				}

				//��������λ��
				key1_x -= 10;
			}

			//�������
			else
			{
				//��ʾ�û�����
				outtextxy(key1_x, key1_y, key1);

				//���û����������Ĵ���
				if (i == 0)
				{
					_username1 += key1;
				}
				else
				{
					_password1 += key1;
				}

				//ǰ������λ��
				key1_x += 10;
			}
		}
	}

	//���Ĵ����е���Ϣ����ʵ����������
	P1.SetId(_username1);
	P1.SetPassword(_password1);

	//��Ҷ�����Ϣ����
	for (int i = 0; i < 2; i++)
	{
		//��������λ�����ڿ�
		setfillcolor(WHITE);
		fillcircle(390, 210, 8);

		//�����x��y����
		int key1_x = 240;
		int key1_y = 200 + i * 30;

		while (1)
		{
			//��ȡ�û�����
			key1 = _getch();

			//���в���
			if (key1 == 13)   //���س���
			{
				setfillcolor(WHITE);
				fillcircle(390, 240, 8);    //��������λ��
				break;
			}

			//Esc��
			else if (key1 == 27)
			{
				settextstyle(20, 0, L"������κ");
				outtextxy(20, 60, L"���أ�");
				outtextxy(20, 90, L"���䣿");
				outtextxy(15, 120, L"��������꣩");
				m_judge = 2;
				return;
			}

			//�������
			else if (key1 == 8)   //��Backspace��
			{
				//�˸�
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key1_x - 10, key1_y, key1_x, key1_y + 20);

				//ɾȥ��һ���ַ�
				if (i == 0)
				{
					_username2.erase(_username2.size() - 1);
				}
				else
				{
					_password2.erase(_password2.size() - 1);
				}

				//��������λ��
				key1_x -= 10;
			}

			//�������
			else
			{
				//��ʾ�û�����
				outtextxy(key1_x, key1_y, key1);

				//���û����������Ĵ���
				if (i == 0)
				{
					_username2 += key1;
				}
				else
				{
					_password2 += key1;
				}

				//ǰ������λ��
				key1_x += 10;
			}
		}
	}

	//���Ĵ����е���Ϣ����ʵ����������
	P2.SetId(_username2);
	P2.SetPassword(_password2);

	//�ж��û��Ƿ����
	for (int i = 0, j = 0; i < m_size; i++)
	{
		if (P1.GetId() == m_playerlist[i]->GetId() && P1.Getpassword() == m_playerlist[i]->Getpassword())
		{
			j++;
			*np1 = i;
		}
		else if (P2.GetId() == m_playerlist[i]->GetId() && P2.Getpassword() == m_playerlist[i]->Getpassword())   //else if����ͬʱ�ų���λ�����ȫ��ͬ�����
		{
			j++;
			*np2 = i;
		}
		if (j == 2)       //j��ֵΪ2˵����λ����û����������������ȷ�����Խ�����Ϸ������judge���أ���֮����˵���������󣬲���judge����
		{
			settextstyle(50, 0, L"������κ");
			outtextxy(190, 280, L"��ʼ��Ϸ");
			outtextxy(10, 280, L"����");
			outtextxy(500, 280, L"����");
			m_judge = 1;                     //��judge���أ����Խ�����Ϸ
			return;
		}
	}

	//�û����������������������judge���أ�����ѡ����������򷵻�
	settextstyle(20, 0, L"������κ");
	outtextxy(390, 10, L"�û����������������");
	outtextxy(430, 30, L"�����������");
	settextstyle(50, 0, L"������κ");
	outtextxy(10, 280, L"����");
	return;
}
void Loginpage::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	FlushMouseMsgBuffer();//��������Ϣ����
	while (1)
	{
		while (MouseHit())    //����굥��ʱ
		{
			//��ȡ�����Ϣ
			m = GetMouseMsg();
			if ((m.x >= 190 && m.x <= 380) && (m.y >= 280 && m.y <= 320))//������Ϻ󣬽�����Ϸҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)
				{
					PageNum = 1;
					return;
				}
			}
			else if ((m.x >= 500 && m.x <= 600) && (m.y >= 280 && m.y <= 320))//������Ϻ����½����¼ҳ�����
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//������Ϻ󣬷�����ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN && (m_judge == 1 || m_judge == 0))
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 390 && m.x <= 590) && (m.y >= 10 && m.y <= 50))//�û������������ʱ�����½����¼ҳ�����
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 60 && m.y <= 80))//��Esc���󣬷�����ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 2)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 90 && m.y <= 110))//��Esc�������½����¼ҳ�����
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 2)
				{
					PageNum = 2;
					return;
				}
			}

		}
	}
}