#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
using namespace std;
//����ҳ����
class Settingpage :public Page
{
public:
	//���캯��
	Settingpage(IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;

	}

	//��ʾҳ��Ԫ�غ���
	void DrawCharacter();

	//����������
	void Mousehit();
};
