#include"Settingpage.h"
using namespace std;
//��ʾҳ��Ԫ�غ���
void Settingpage::DrawCharacter()
{
	//��ʾ����ͼƬ
	DrawBK();

	settextcolor(WHITE);                     //����������ɫ
	setbkmode(TRANSPARENT);                  //ȥ������ĺڿ� 
	settextstyle(50, 0, L"������κ");        //�����������ͼ���С

	//��ʾ����ѡ��
	outtextxy(190, 50, L"��Ϸ����");
	outtextxy(190, 150, L"��������");
	outtextxy(240, 250, L"����");
}
//����������
void Settingpage::Mousehit()
{
	//���������Ϣ
	MOUSEMSG m;
	//��������Ϣ����
	FlushMouseMsgBuffer();

	while (1)
	{
		while (MouseHit())      //����굥��ʱ
		{
			//��ȡ�����Ϣ
			m = GetMouseMsg();
			if ((m.x >= 190 && m.x <= 390) && (m.y >= 50 && m.y <= 100))   //���ñ���
			{
				if (m.uMsg == WM_LBUTTONDOWN)      //��������������ͬ
				{
					PageNum = 6;
					return;
				}
			}
			else if ((m.x >= 240 && m.x <= 340) && (m.y >= 250 && m.y <= 300))   //����
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 190 && m.x <= 390) && (m.y >= 150 && m.y <= 200))    //��������
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PageNum = 7;
					return;
				}
			}
		}
	}
}