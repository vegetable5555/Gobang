#include"player.h"
//获取用户名
string Player::GetId()
{
	return m_ID;
}
//获取密码
string Player::Getpassword()
{
	return m_password;
}
//获取成绩
int Player::Getmark()
{
	return m_mark;
}
//获取等级
char Player::GetLevel()
{
	return m_level;
}
//设置用户名
void Player::SetId(string id)
{
	m_ID = id;
}
//设置密码
void Player::SetPassword(string password)
{
	m_password = password;
}
//设置成绩
void Player::SetMark(int mark)
{
	m_mark = mark;
}
//设置等级
void  Player::SetLevel(char level)
{
	m_level = level;
}
