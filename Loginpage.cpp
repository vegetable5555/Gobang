#include"Loginpage.h"
using namespace std;
void Loginpage::DrawCharacter()
{
	//实例化文本框对象
	TextBox username1(240, 85, 380, 105);
	TextBox password1(240, 115, 380, 135);
	TextBox username2(240, 200, 380, 220);
	TextBox password2(240, 230, 380, 250);

	//显示背景图片
	DrawBK();

	settextcolor(WHITE);                     //设置字体颜色
	setbkmode(TRANSPARENT);                  //去除字体的黑框 
	settextstyle(50, 0, L"华文新魏");        //设置字体类型及大小

	//显示各项选择
	outtextxy(210, 30, L"玩家一");
	outtextxy(210, 150, L"玩家二");

	settextstyle(20, 0, L"华文新魏");        //更新字体大小

	outtextxy(170, 85, L"用户名：");
	outtextxy(170, 115, L"密码：");
	outtextxy(170, 200, L"用户名：");
	outtextxy(170, 230, L"密码：");
	outtextxy(10, 10, L" 按ESC键返回主页面");
	outtextxy(10, 30, L"或重新进入登录页面");

	//显示用户名和密码输入框
	username1.Draw();
	password1.Draw();
	username2.Draw();
	password2.Draw();
}
void Loginpage::Input(int* np1, int* np2)
{
	//两名玩家
	Player P1;
	Player P2;

	//用户名和密码的寄存器
	string _username1;
	string _password1;
	string _username2;
	string _password2;

	//用户的键盘输入
	char key1;

	//玩家一的信息输入
	for (int i = 0; i < 2; i++)
	{
		//提醒输入位置所在框
		setfillcolor(WHITE);
		fillcircle(390, 95, 8);

		//输入的x、y坐标
		int key1_x = 240;
		int key1_y = 85 + i * 30;

		while (1)
		{
			//获取用户输入
			key1 = _getch();

			//换行操作
			if (key1 == 13)     //（回车）
			{
				setfillcolor(WHITE);       //提醒输入位置
				fillcircle(390, 125, 8);
				break;
			}

			//Esc键
			else if (key1 == 27)
			{
				settextstyle(20, 0, L"华文新魏");
				outtextxy(20, 60, L"返回？");
				outtextxy(20, 90, L"重输？");
				outtextxy(15, 120, L"（单击鼠标）");
				m_judge = 2;
				return;
			}

			//错输操作
			else if (key1 == 8)       //（Backspace）
			{
				//退格
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key1_x - 10, key1_y, key1_x, key1_y + 20);

				//删去上一个字符
				if (i == 0)
				{
					_username1.erase(_username1.size() - 1);
				}
				else
				{
					_password1.erase(_password1.size() - 1);
				}

				//回退输入位置
				key1_x -= 10;
			}

			//输入操作
			else
			{
				//显示用户输入
				outtextxy(key1_x, key1_y, key1);

				//将用户的输入存进寄存器
				if (i == 0)
				{
					_username1 += key1;
				}
				else
				{
					_password1 += key1;
				}

				//前推输入位置
				key1_x += 10;
			}
		}
	}

	//将寄存器中的信息存入实例化对象中
	P1.SetId(_username1);
	P1.SetPassword(_password1);

	//玩家二的信息输入
	for (int i = 0; i < 2; i++)
	{
		//提醒输入位置所在框
		setfillcolor(WHITE);
		fillcircle(390, 210, 8);

		//输入的x、y坐标
		int key1_x = 240;
		int key1_y = 200 + i * 30;

		while (1)
		{
			//获取用户输入
			key1 = _getch();

			//换行操作
			if (key1 == 13)   //（回车）
			{
				setfillcolor(WHITE);
				fillcircle(390, 240, 8);    //提醒输入位置
				break;
			}

			//Esc键
			else if (key1 == 27)
			{
				settextstyle(20, 0, L"华文新魏");
				outtextxy(20, 60, L"返回？");
				outtextxy(20, 90, L"重输？");
				outtextxy(15, 120, L"（单击鼠标）");
				m_judge = 2;
				return;
			}

			//错输操作
			else if (key1 == 8)   //（Backspace）
			{
				//退格
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key1_x - 10, key1_y, key1_x, key1_y + 20);

				//删去上一个字符
				if (i == 0)
				{
					_username2.erase(_username2.size() - 1);
				}
				else
				{
					_password2.erase(_password2.size() - 1);
				}

				//回退输入位置
				key1_x -= 10;
			}

			//输入操作
			else
			{
				//显示用户输入
				outtextxy(key1_x, key1_y, key1);

				//将用户的输入存进寄存器
				if (i == 0)
				{
					_username2 += key1;
				}
				else
				{
					_password2 += key1;
				}

				//前推输入位置
				key1_x += 10;
			}
		}
	}

	//将寄存器中的信息存入实例化对象中
	P2.SetId(_username2);
	P2.SetPassword(_password2);

	//判断用户是否存在
	for (int i = 0, j = 0; i < m_size; i++)
	{
		if (P1.GetId() == m_playerlist[i]->GetId() && P1.Getpassword() == m_playerlist[i]->Getpassword())
		{
			j++;
			*np1 = i;
		}
		else if (P2.GetId() == m_playerlist[i]->GetId() && P2.Getpassword() == m_playerlist[i]->Getpassword())   //else if语句可同时排除两位玩家完全相同的情况
		{
			j++;
			*np2 = i;
		}
		if (j == 2)       //j的值为2说明两位玩家用户名和密码均输入正确，可以进入游戏，并打开judge开关，反之，则说明输入有误，不打开judge开关
		{
			settextstyle(50, 0, L"华文新魏");
			outtextxy(190, 280, L"开始游戏");
			outtextxy(10, 280, L"返回");
			outtextxy(500, 280, L"重输");
			m_judge = 1;                     //打开judge开关，可以进入游戏
			return;
		}
	}

	//用户名或密码错误的情况，不打开judge开关，可以选择重新输入或返回
	settextstyle(20, 0, L"华文新魏");
	outtextxy(390, 10, L"用户名或密码输入错误");
	outtextxy(430, 30, L"点击重新输入");
	settextstyle(50, 0, L"华文新魏");
	outtextxy(10, 280, L"返回");
	return;
}
void Loginpage::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	FlushMouseMsgBuffer();//清空鼠标信息缓存
	while (1)
	{
		while (MouseHit())    //当鼠标单击时
		{
			//获取鼠标信息
			m = GetMouseMsg();
			if ((m.x >= 190 && m.x <= 380) && (m.y >= 280 && m.y <= 320))//输入完毕后，进入游戏页面
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)
				{
					PageNum = 1;
					return;
				}
			}
			else if ((m.x >= 500 && m.x <= 600) && (m.y >= 280 && m.y <= 320))//输入完毕后，重新进入登录页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//输入完毕后，返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN && (m_judge == 1 || m_judge == 0))
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 390 && m.x <= 590) && (m.y >= 10 && m.y <= 50))//用户名与密码错误时，重新进入登录页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{
					PageNum = 2;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 60 && m.y <= 80))//按Esc键后，返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 2)
				{
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 20 && m.x <= 70) && (m.y >= 90 && m.y <= 110))//按Esc键后，重新进入登录页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 2)
				{
					PageNum = 2;
					return;
				}
			}

		}
	}
}