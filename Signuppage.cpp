#include"Signuppage.h"
//��ʾҳ��Ԫ�غ���
void Signuppage::DrawCharacter()
{
	//�ı������
	TextBox username(240, 135, 400, 165);
	TextBox password(240, 195, 400, 225);

	//��ʾ����ͼƬ
	DrawBK();

	settextcolor(WHITE);                     //������ɫ
	setbkmode(TRANSPARENT);                  //ȥ����ɫ�ĺڿ� 
	settextstyle(50, 0, L"������κ");        //�����������ͼ���С

	//��ʾ����ѡ��
	outtextxy(180, 50, L"ע�����û�");

	settextstyle(20, 0, L"������κ");        //���������С

	outtextxy(10, 10, L" ��ESC��������ҳ��");
	outtextxy(10, 30, L"�����½����¼ҳ��");

	settextstyle(30, 0, L"������κ");        //���������С

	outtextxy(140, 135, L"�û�����");
	outtextxy(150, 195, L"���룺");

	//�û��������������
	username.Draw();
	password.Draw();
}
//�����������
void Signuppage::Input()
{
	//�����������ͼ���С
	settextstyle(30, 0, L"������κ");

	//�½��û�����
	Player P;

	//�û���������ļĴ���
	string _username;
	string _password;

	//�û�������
	char key2;

	//ע����Ϣ����
	for (int i = 0; i < 2; i++)
	{
		//��������λ�����ڿ�
		setfillcolor(WHITE);
		fillcircle(420, 150, 10);

		//�����x��y����
		int key_x = 240;
		int key_y = 135 + i * 60;

		while (1)
		{
			//��ȡ�û�����
			char key = _getch();

			//���в���
			if (key == 13)    //���س���
			{
				setfillcolor(WHITE);
				fillcircle(420, 210, 10);    //��������λ��
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

			//�������
			else if (key == 8)    //��Backspace��
			{
				//�˸�
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key_x - 15, key_y, key_x, key_y + 30);

				//ɾȥ��һ���ַ�
				if (i == 0)
				{
					_username.erase(_username.size() - 1);
				}
				else
				{
					_password.erase(_password.size() - 1);
				}

				//��������λ��
				key_x -= 15;
			}

			//�������
			else
			{
				//���û����������Ĵ���
				if (i == 0)
				{
					_username += key;
					outtextxy(key_x, key_y, key);
				}
				else
				{
					_password += key;
					outtextxy(key_x, key_y, key);
				}

				//ǰ������λ��
				key_x += 15;
			}
		}

	}

	//���Ĵ����е���Ϣ����ʵ��������
	P.SetId(_username);
	P.SetPassword(_password);

	//�ж��û��Ƿ��Ѵ���,�����ڣ����½����û�
	for (int i = 0; i < *m_size; i++)   //���������ѽ��û�
	{
		if (P.GetId() == m_playerlist[i]->GetId())
		{
			settextstyle(20, 0, L"������κ");      //���������С
			outtextxy(250, 230, L"������Ѵ���");
			outtextxy(250, 255, L"�����������");
			settextstyle(50, 0, L"������κ");
			outtextxy(10, 280, L"����");
			return;
		}
	}

	settextstyle(50, 0, L"������κ");   //���������С
	outtextxy(250, 280, L"ע��");   //ȷ��ע��

	m_judge = 1;          //���д������˵��������ͬ���û�������ע�ᣬ����judge����
	m_playerlist[*m_size] = new Player(P.GetId(), P.Getpassword());     //�������������
	return;
}
//����������
void Signuppage::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	FlushMouseMsgBuffer();//��������Ϣ����
	while (1)
	{
		while (MouseHit())       //����굥��ʱ
		{
			//��ȡ�����Ϣ
			m = GetMouseMsg();
			if ((m.x >= 250 && m.x <= 350) && (m.y >= 280 && m.y <= 320))//������Ϻ�ע��ȷ�ϣ���������ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)     //�����������ͬ
				{
					(*m_size)++;             //�������鳤��
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 250 && m.x <= 370) && (m.y >= 255 && m.y <= 275))//�û����ڣ����½���ע��ҳ�����
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{

					PageNum = 3;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//������Ϻ�ȡ��ע���������������ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{
					PageNum = 0;
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
					PageNum = 3;
					return;
				}
			}
		}
	}
}