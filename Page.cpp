#include"Page.h"
//��ʼ����̬��ԱPageNum
int Page::PageNum = 0;
//��ʾ����ͼƬ
void Page::DrawBK()
{
	//��ȡ��Ƭ�ĳߴ�
	int width = m_bkimage.getwidth();
	int height = m_bkimage.getheight();
	//���ڴ��ڴ�С
	initgraph(width, height);
	//��ʾͼƬ
	putimage(0, 0, &m_bkimage);
}