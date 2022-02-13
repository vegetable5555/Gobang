#pragma once
#include<iostream>
using namespace std;
//�����
class Player
{
public:
	//Ĭ�Ϲ��캯��
	Player() {}
	//�вι��캯��
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

	//��ȡ����
	string Getpassword();
	//��ȡ�û���
	string GetId();
	//��ȡ�ɼ�
	int Getmark();
	//��ȡ�ȼ�
	char GetLevel();

	//�����û���
	void SetId(string id);
	//��������
	void SetPassword(string password);
	//���óɼ�
	void SetMark(int mark);
	//���õȼ�
	void SetLevel(char level);

protected:
	string m_ID, m_password;
	int m_mark;
	char m_level;
};
