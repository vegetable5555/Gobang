#pragma once
#include<iostream>
#include"player.h"
#include<fstream>
using namespace std;
const Player mark = { "0","0",0 };
void writefilebin(Player** PL, int n);
int EndMark(Player p);