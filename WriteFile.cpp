#include"WriteFile.h"
void writefilebin(Player** PL, int n)
{
	ofstream outfile;
	outfile.open("playerdata.dat", ios::out | ios::binary);
	outfile.seekp(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		outfile.write((char*)&(*PL[i]), sizeof(Player));
	}
	outfile.write((char*)&(mark), sizeof(Player));
}
int EndMark(Player p)
{
	if (p.GetId() == "0" && p.Getpassword() == "0")
		return 1;
	return 0;
}