#include"Gamebeginpage.h"
#include"Page.h"
void GameBeginPage::DrawCharacter()
{
	settextstyle(50, 0, L"������κ");     //�����������ͼ���С
	setbkmode(TRANSPARENT);               //ȥ����ɫ�ĺڿ� 
	settextcolor(WHITE);                  //����������ɫ

	//��ʾ����ѡ��
	outtextxy(230, 30, L"��¼");
	outtextxy(230, 100, L"ע��");
	outtextxy(210, 180, L"���а�");
	outtextxy(230, 260, L"����");

	settextstyle(30, 0, L"������κ");      //���������С

	outtextxy(10, 10, L"�޸��˺�");
	outtextxy(10, 50, L"�޸�����");
}
void GameBeginPage::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	FlushMouseMsgBuffer();//��������Ϣ����
	while (1)
	{
		while (MouseHit())          //����굥��ʱ
		{
			m = GetMouseMsg();      //��ȡ�����Ϣ
			if ((m.x >= 230 && m.x <= 320) && (m.y >= 30 && m.y <= 75))       //��ת����¼ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)            //�����������ͬ
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 230 && m.x <= 320) && (m.y >= 100 && m.y <= 145))     //��ת��ע��ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 3;
					return;
				}
			}
			else if (((m.x >= 230 && m.x <= 320) && (m.y >= 180 && m.y <= 225)))    //��ת�����а�ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 4;
					return;
				}
			}
			else if (((m.x >= 230 && m.x <= 320) && (m.y >= 260 && m.y <= 305)))     //��ת������ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 5;
					return;
				}
			}
			else if (((m.x >= 10 && m.x <= 130) && (m.y >= 10 && m.y <= 40)))         //��ת���޸��˺�ҳ��
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 8;
					return;
				}
			}
			else if (((m.x >= 10 && m.x <= 130) && (m.y >= 50 && m.y <= 80)))         //��ת���޸�����ҳ��
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