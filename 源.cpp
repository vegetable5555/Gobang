#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<fstream>
#include"Page.h"
#include"player.h"
#include"Loginpage.h"
#include"Signuppage.h"
#include"Settingpage.h"
#include"WriteFile.h"
#include<mmsystem.h>
#include"ChangeIDPage.h"
#include"ChangePWPage.h"
#include"Gamepage.h"
#include"Gamebeginpage.h"
#include"Ranklistpage.h"
#include"Backgroundpage.h"
#include"Backgroundmusicpage.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
int page = 0;
Player players[100];
int main()
{
	//����Ĭ�ϱ���
	IMAGE BGimage1;
	loadimage(&BGimage1, L"bkimage.jpg");
	IMAGE BGimage2;
	loadimage(&BGimage2, L"�ٽ���ӽ.jpg");

	//�����������
	Player* playerlist[100];

	//�������
	int m_size = 0;

	//������Ϸ������������е�λ��
	int np1, np2;

	//�������ñ���ҳ����
	Background settingBG(&BGimage2, BGimage1);

	//���س�ʼ��������
	mciSendString(L"open ҹ������������.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music repeat", 0, 0, 0);

	//�����ļ�������ȡ�ļ�
	ifstream inf("playerdata.dat", ios::in | ios::binary);
	inf.seekg(0, ios::beg);
	while (1)
	{
		inf.read((char*)&(players[m_size]), sizeof(Player));
		playerlist[m_size] = &players[m_size];
		if (EndMark(*playerlist[m_size]))
			break;
		m_size++;
	}

	//playerlist[0] = new Player("p1", "123456", 11);
	//playerlist[1] = new Player("p2", "123456", 9);
	//playerlist[2] = new Player("p3", "123456", 35);
	//playerlist[3] = new Player("p4", "123456", 29);

	//m_size = 4;
	while (1)
	{
		writefilebin(playerlist, m_size);

		//ѡ��ҳ��
		switch (Page::PageNum)
		{
			//��ʼҳ��
		case 0:
		{
			GameBeginPage p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//��Ϸҳ��
		case 1:
		{
			GamePage p(*settingBG.Getm_GBG(), playerlist[np1], playerlist[np2]);
			p.DrawBK();
			p.DrawCharacter();
			p.DrawChessBoard();
			p.Mousehit();
			p.GameClean();
			break;
		}
		//��¼ҳ��
		case 2:
		{
			Loginpage p(BGimage1, playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input(&np1, &np2);
			p.Mousehit();
			break;
		}
		//ע��ҳ��
		case 3:
		{
			Signuppage p(BGimage1, playerlist, &m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input();
			p.Mousehit();
			break;
		}
		//���а�ҳ��
		case 4:
		{
			RankListPage p(*settingBG.Getm_GBG(), playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Rank();
			p.ShowRank();
			p.Mousehit();
			break;
		}
		//����ҳ��
		case 5:
		{
			Settingpage p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//���ñ���ͼƬҳ��
		case 6:
		{
			settingBG.DrawBK();
			settingBG.DrawCharacter();
			settingBG.Mousehit();
			break;
		}
		//���ñ�������ҳ��
		case 7:
		{
			Backgroundmusic p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//�޸��˺�ҳ��
		case 8:
		{
			ChangeIDPage p(BGimage1, playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input();
			p.Mousehit();
			break;
		}
		//�޸�����ҳ��
		case 9:
		{
			ChangePWPage p(BGimage1, playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input();
			p.Mousehit();
			break;
		}
		}
	}
}