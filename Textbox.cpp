#include"Textbox.h"
using namespace std;
//���캯��
TextBox::TextBox(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}
//�����ı�����
void TextBox::Draw()
{
	//�����ı�����ɫ
	setlinecolor(BLACK);
	setfillcolor(BLACK);

	//�����ı���λ�ü���С
	fillrectangle(m_x1, m_y1, m_x2, m_y2);
}
