#pragma once
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"player.h"
#include"Textbox.h"
#include"Page.h"
//��ʼҳ��;
class GameBeginPage :public Page
{
public:
	//���캯��
	GameBeginPage(IMAGE bkimage) :Page(bkimage)
	{}

	//��ʾҳ��Ԫ�غ���
	void DrawCharacter();

	//����������
	void Mousehit();
};