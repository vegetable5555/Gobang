#include"Backgroundmusicpage.h"
void Backgroundmusic::DrawCharacter()
{
	//��ʾ����ͼƬ
	DrawBK();

	settextcolor(WHITE);                     //����������ɫ
	setbkmode(TRANSPARENT);                  //ȥ������ĺڿ� 
	settextstyle(30, 0, L"������κ");        //�����������ͼ���С

	//��ʾ����ѡ��
	outtextxy(210, 40, L"���Źŵ�");
	outtextxy(165, 90, L"ҹ������������");
	outtextxy(240, 140, L"��Ա");
	outtextxy(240, 190, L"����");
	outtextxy(210, 240, L"�ر�����");
	settextstyle(50, 0, L"������κ");        //���������С
	outtextxy(10, 280, L"����");
}
void Backgroundmusic::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	//��������Ϣ����
	FlushMouseMsgBuffer();
	while (1)
	{
		while (MouseHit())          //����굥��ʱ
		{
			m = GetMouseMsg();      //��ȡ�����Ϣ
			if ((m.x >= 210 && m.x <= 330) && (m.y >= 40 && m.y <= 70))
			{
				if (m.uMsg == WM_LBUTTONDOWN)                                   //�������
				{
					mciSendString(L"close music", 0, 0, 0);                     //�ر�ԭʼ����
					mciSendString(L"open ���Źŵ�.mp3 alias music", 0, 0, 0);   //��������
					mciSendString(L"play music repeat", 0, 0, 0);               //�����ظ�����
					PageNum = 5;                                                //��������ҳ��
					return;                                                     //��ͬ
				}
			}
			else if ((m.x >= 165 && m.x <= 375) && (m.y >= 90 && m.y <= 120))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					mciSendString(L"open ҹ������������.mp3 alias music", 0, 0, 0);
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
					mciSendString(L"open ��Ա.mp3 alias music", 0, 0, 0);
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
					mciSendString(L"open ����.mp3 alias music", 0, 0, 0);
					mciSendString(L"play music repeat", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 210 && m.x <= 330) && (m.y >= 240 && m.y <= 270))//�ر�����
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mciSendString(L"close music", 0, 0, 0);
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//ֱ�ӷ�������ҳ��
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