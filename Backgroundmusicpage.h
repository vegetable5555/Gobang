#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
//��������ҳ��
class Backgroundmusic :public Page
{
public:
	//���캯��
	Backgroundmusic(IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;
	}

	//��ʾ��ҳ��Ԫ�غ���
	void DrawCharacter();

	//����������
	void Mousehit();
}; 
