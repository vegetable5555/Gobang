#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Page.h"
//���ñ���ҳ��
class Background :public Page
{
public:
	//���캯��
	Background(IMAGE* GBG, IMAGE bkimage) :Page(bkimage)
	{
		m_bkimage = bkimage;                //���뱾ҳ��ı���ͼƬ
		m_GBG = GBG;                        //���뱳��ͼƬ��ַ
		loadimage(m_GBG, L"�ٽ���ӽ.jpg");  //����Ĭ�ϱ���
	}

	//��ʾ��ҳ��Ԫ�غ���
	void DrawCharacter();

	//����������
	void Mousehit();

	//��ȡ����ͼƬ��ַ
	IMAGE* Getm_GBG();

protected:
	IMAGE* m_GBG;
};