#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Textbox.h"
#include"player.h"
#include"Page.h"
using namespace std;
//ע��ҳ����
class Signuppage :public Page
{
public:
	//���캯��
	Signuppage(IMAGE bkimage, Player* playerlist[100], int* size) :Page(bkimage)
	{
		m_bkimage = bkimage;
		m_playerlist = playerlist;
		m_size = size;
		m_judge = 0;
	}

	//��ʾҳ��Ԫ�غ���
	void DrawCharacter();

	//���������������
	void Input();

	//����������
	void Mousehit();

protected:
	Player** m_playerlist;
	int* m_size;
	int m_judge;
};
