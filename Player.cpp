#include"player.h"
//��ȡ�û���
string Player::GetId()
{
	return m_ID;
}
//��ȡ����
string Player::Getpassword()
{
	return m_password;
}
//��ȡ�ɼ�
int Player::Getmark()
{
	return m_mark;
}
//��ȡ�ȼ�
char Player::GetLevel()
{
	return m_level;
}
//�����û���
void Player::SetId(string id)
{
	m_ID = id;
}
//��������
void Player::SetPassword(string password)
{
	m_password = password;
}
//���óɼ�
void Player::SetMark(int mark)
{
	m_mark = mark;
}
//���õȼ�
void  Player::SetLevel(char level)
{
	m_level = level;
}
