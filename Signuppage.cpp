#include"Signuppage.h"
//显示页面元素函数
void Signuppage::DrawCharacter()
{
	//文本框对象
	TextBox username(240, 135, 400, 165);
	TextBox password(240, 195, 400, 225);

	//显示背景图片
	DrawBK();

	settextcolor(WHITE);                     //字体颜色
	setbkmode(TRANSPARENT);                  //去除颜色的黑框 
	settextstyle(50, 0, L"华文新魏");        //设置字体类型及大小

	//显示各项选择
	outtextxy(180, 50, L"注册新用户");

	settextstyle(20, 0, L"华文新魏");        //更新字体大小

	outtextxy(10, 10, L" 按ESC键返回主页面");
	outtextxy(10, 30, L"或重新进入登录页面");

	settextstyle(30, 0, L"华文新魏");        //更新字体大小

	outtextxy(140, 135, L"用户名：");
	outtextxy(150, 195, L"密码：");

	//用户名和密码输入框
	username.Draw();
	password.Draw();
}
//输入操作函数
void Signuppage::Input()
{
	//设置字体类型及大小
	settextstyle(30, 0, L"华文新魏");

	//新建用户对象
	Player P;

	//用户名与密码的寄存器
	string _username;
	string _password;

	//用户的输入
	char key2;

	//注册信息输入
	for (int i = 0; i < 2; i++)
	{
		//提醒输入位置所在框
		setfillcolor(WHITE);
		fillcircle(420, 150, 10);

		//输入的x、y坐标
		int key_x = 240;
		int key_y = 135 + i * 60;

		while (1)
		{
			//获取用户输入
			char key = _getch();

			//换行操作
			if (key == 13)    //（回车）
			{
				setfillcolor(WHITE);
				fillcircle(420, 210, 10);    //提醒输入位置
				break;
			}

			//Esc键
			else if (key == 27)
			{
				settextstyle(20, 0, L"华文新魏");
				outtextxy(20, 60, L"返回？");
				outtextxy(20, 90, L"重输？");
				outtextxy(15, 120, L"（单击鼠标）");
				m_judge = 2;
				return;
			}

			//错输操作
			else if (key == 8)    //（Backspace）
			{
				//退格
				setlinecolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(key_x - 15, key_y, key_x, key_y + 30);

				//删去上一个字符
				if (i == 0)
				{
					_username.erase(_username.size() - 1);
				}
				else
				{
					_password.erase(_password.size() - 1);
				}

				//回退输入位置
				key_x -= 15;
			}

			//输入操作
			else
			{
				//将用户的输入存进寄存器
				if (i == 0)
				{
					_username += key;
					outtextxy(key_x, key_y, key);
				}
				else
				{
					_password += key;
					outtextxy(key_x, key_y, key);
				}

				//前推输入位置
				key_x += 15;
			}
		}

	}

	//将寄存器中的信息存入实例化对象
	P.SetId(_username);
	P.SetPassword(_password);

	//判断用户是否已存在,若存在，则新建该用户
	for (int i = 0; i < *m_size; i++)   //遍历所有已建用户
	{
		if (P.GetId() == m_playerlist[i]->GetId())
		{
			settextstyle(20, 0, L"华文新魏");      //更新字体大小
			outtextxy(250, 230, L"该玩家已存在");
			outtextxy(250, 255, L"点击重新输入");
			settextstyle(50, 0, L"华文新魏");
			outtextxy(10, 280, L"返回");
			return;
		}
	}

	settextstyle(50, 0, L"华文新魏");   //更新字体大小
	outtextxy(250, 280, L"注册");   //确定注册

	m_judge = 1;          //运行此条语句说明不存在同样用户，可以注册，并打开judge开关
	m_playerlist[*m_size] = new Player(P.GetId(), P.Getpassword());     //将对象存入数组
	return;
}
//鼠标操作函数
void Signuppage::Mousehit()
{
	//鼠标坐标信息
	MOUSEMSG m;
	FlushMouseMsgBuffer();//清空鼠标信息缓存
	while (1)
	{
		while (MouseHit())       //当鼠标单击时
		{
			//获取鼠标信息
			m = GetMouseMsg();
			if ((m.x >= 250 && m.x <= 350) && (m.y >= 280 && m.y <= 320))//输入完毕后，注册确认，并返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 1)     //单击左键，下同
				{
					(*m_size)++;             //增加数组长度
					PageNum = 0;
					return;
				}
			}
			else if ((m.x >= 250 && m.x <= 370) && (m.y >= 255 && m.y <= 275))//用户存在，重新进入注册页面操作
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{

					PageNum = 3;
					return;
				}
			}
			else if ((m.x >= 10 && m.x <= 105) && (m.y >= 280 && m.y <= 320))//输入完毕后，取消注册操作，并返回主页面
			{
				if (m.uMsg == WM_LBUTTONDOWN && m_judge == 0)
				{
					PageNum = 0;
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
					PageNum = 3;
					return;
				}
			}
		}
	}
}