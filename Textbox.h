#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
//�ı�����
class TextBox
{
public:
	//���캯��
	TextBox(int x1, int y1, int x2, int y2);

	//�����ı���
	void Draw();

private:
	//�ı�������
	int m_x1, m_x2, m_y1, m_y2;
};
