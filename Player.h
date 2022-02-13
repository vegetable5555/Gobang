#pragma once
#include<iostream>
using namespace std;
//玩家类
class Player
{
public:
	//默认构造函数
	Player() {}
	//有参构造函数
	Player(string ID, string password, int mark = 0)
	{
		m_ID = ID;
		m_password = password;
		m_mark = mark;
		if (mark >= 0 && mark <= 10)
			m_level = 'C';
		if (mark > 10 && mark <= 30)
			m_level = 'B';
		if (mark > 30)
			m_level = 'A';
	}

	//获取密码
	string Getpassword();
	//获取用户名
	string GetId();
	//获取成绩
	int Getmark();
	//获取等级
	char GetLevel();

	//设置用户名
	void SetId(string id);
	//设置密码
	void SetPassword(string password);
	//设置成绩
	void SetMark(int mark);
	//设置等级
	void SetLevel(char level);

protected:
	string m_ID, m_password;
	int m_mark;
	char m_level;
};
