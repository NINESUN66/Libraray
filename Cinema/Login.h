#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include"SignUp.h"
using namespace std;
class AP
{
public:
	AP(string ac, string pa)
	{
		m_Ac = ac;
		m_Pa = pa;
	}

	string m_Ac;
	string m_Pa;
};

int Login();