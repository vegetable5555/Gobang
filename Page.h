#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
using namespace std;
//����ҳ��
class Page
{
public:
	static int PageNum;
	//���캯��
	Page(IMAGE bkimage)
	{
		m_bkimage = bkimage;
	}

	//��ʾ����ͼƬ
	void DrawBK();

	//��ʾҳ��Ԫ�غ��������Ĵ��麯��
	virtual void DrawCharacter() = 0;
	virtual void Mousehit() = 0;

protected:
	IMAGE m_bkimage;

};