#include"Backgroundpage.h"
//��ȡ����ͼƬ��ַ
IMAGE* Background::Getm_GBG()
{
	return m_GBG;
}
//��ʾҳ��Ԫ�غ���
void Background::DrawCharacter()
{
	//��ʾ����ͼƬ
	DrawBK();

	settextcolor(WHITE);                     //����������ɫ
	setbkmode(TRANSPARENT);                  //ȥ������ĺڿ� 
	settextstyle(30, 0, L"������κ");        //�����������ͼ���С

	//��ʾ��ѡ����
	outtextxy(190, 40, L"��ɫ����");
	outtextxy(190, 90, L"��������");
	outtextxy(190, 140, L"�ٽ���ӽ");
	outtextxy(190, 190, L"��īɽˮ");
	outtextxy(190, 240, L"�Ƽ��籩");
	settextstyle(50, 0, L"������κ");         //���������С
	outtextxy(10, 280, L"����");
}
//����������
void Background::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	//��������Ϣ����
	FlushMouseMsgBuffer();
	while (1)
	{
		while (MouseHit())      //����굥��ʱ
		{
			m = GetMouseMsg();  //��ȡ�����Ϣ
			if ((m.x >= 190 && m.x <= 310) && (m.y >= 40 && m.y <= 70))
			{
				if (m.uMsg == WM_LBUTTONDOWN)                //�������
				{
					loadimage(m_GBG, L"��ɫ����.jpg");       //���ض�Ӧ����ͼƬ
					PageNum = 5;                             //��������ҳ��
					return;                                  //��ͬ
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 90 && m.y <= 120))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"��������.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 140 && m.y <= 170))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"�ٽ���ӽ.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 190 && m.y <= 220))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"��īɽˮ.jpg");
					PageNum = 5;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 310) && (m.y >= 240 && m.y <= 270))
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					loadimage(m_GBG, L"�Ƽ��籩.jpg");
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