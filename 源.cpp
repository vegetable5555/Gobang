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
	//加载默认背景
	IMAGE BGimage1;
	loadimage(&BGimage1, L"bkimage.jpg");
	IMAGE BGimage2;
	loadimage(&BGimage2, L"临江赋咏.jpg");

	//定义玩家数组
	Player* playerlist[100];

	//玩家数量
	int m_size = 0;

	//进行游戏的玩家在数组中的位置
	int np1, np2;

	//定义设置背景页面类
	Background settingBG(&BGimage2, BGimage1);

	//加载初始背景音乐
	mciSendString(L"open 夜空中最亮的星.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music repeat", 0, 0, 0);

	//定义文件流，读取文件
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

		//选择页面
		switch (Page::PageNum)
		{
			//初始页面
		case 0:
		{
			GameBeginPage p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//游戏页面
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
		//登录页面
		case 2:
		{
			Loginpage p(BGimage1, playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input(&np1, &np2);
			p.Mousehit();
			break;
		}
		//注册页面
		case 3:
		{
			Signuppage p(BGimage1, playerlist, &m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input();
			p.Mousehit();
			break;
		}
		//排行榜页面
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
		//设置页面
		case 5:
		{
			Settingpage p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//设置背景图片页面
		case 6:
		{
			settingBG.DrawBK();
			settingBG.DrawCharacter();
			settingBG.Mousehit();
			break;
		}
		//设置背景音乐页面
		case 7:
		{
			Backgroundmusic p(BGimage1);
			p.DrawBK();
			p.DrawCharacter();
			p.Mousehit();
			break;
		}
		//修改账号页面
		case 8:
		{
			ChangeIDPage p(BGimage1, playerlist, m_size);
			p.DrawBK();
			p.DrawCharacter();
			p.Input();
			p.Mousehit();
			break;
		}
		//修改密码页面
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