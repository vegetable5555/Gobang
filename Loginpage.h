#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Textbox.h"
#include"Player.h"
#include"Page.h"
using namespace std;
//��¼ҳ����
class Loginpage :public Page
{
public:
	//���캯��
	Loginpage(IMAGE bkimage, Player* playerlist[100], int size) :Page(bkimage)
	{
		m_bkimage = bkimage;         //���ñ�ҳ����
		m_playerlist = playerlist;   //�����������
		m_size = size;               //����Ŀǰ�������
		m_judge = 0;                 //ҳ����ӿڿ���
	}
	//��ʾ��ҳ��Ԫ�غ���
	void DrawCharacter();

	//���������������
	void Input(int* np1, int* np2);

	//����������
	void Mousehit();

protected:
	Player** m_playerlist;
	int m_size;
	int m_judge;
};
