#include"SignUp.h"
#include <fstream>
#include<iostream>
#include<conio.h>
using namespace std;

#define AP "Account.txt"  // �����ļ�·��
string Password1 = "";
string Password2 = "";

void BuildPassword()
{
    Password1 = "";
    Password2 = "";
    cout << "��������������:";
    char p;
    while (p = _getch())  // ��ȡ������ַ���������ʾ����Ļ��
    {
        if (p == '\r') break;  // ������»س��������˳�ѭ��
        if (p == 8 && Password1 != "")
        {
            cout << char(8) << " " << char(8);  // ����ϴ�������ַ�
            Password1.pop_back();  // �������ַ�����ɾ�����һ���ַ�
        }
        if (p >= 32)
        {
            if (p != 32) Password1 = Password1 + p;  // ���ַ���ӵ������ַ�����
            cout << "*";  // ��ʾ '*' ���������ַ�
        }
    }
    cout << endl;
    cout << "���ٴ�ȷ����������:";
    while (p = _getch())
    {
        if (p == '\r') break;
        if (p == 8 && Password2 != "")
        {
            cout << char(8) << " " << char(8);
            Password2.pop_back();
        }
        if (p >= 32)
        {
            if (p != 32) Password2 = Password2 + p;
            cout << "*";
        }
    }
}

void AccPass::SignUp()
{
    ofstream ofs;
    ofs.open(AP, ios::out | ios::app);  // ���ļ�����д�벢��д��ָ�붨λ���ļ�ĩβ
    cout << "�����������˺�:"; 
    string Account;
    cin >> m_Account;
    BuildPassword();  // ���ú����Ի�ȡ�û���������룬���洢�� Password1 �� Password2 ��

    if (Password1 != Password2)  // �����������������Ƿ�һ��
    {
        cout << "�������벻һ�£�����������" << endl;
        BuildPassword();  // ���»�ȡ����
    }

    m_Password = Password1;  // �� Password1 ��ֵ����Ա���� m_Password
    ofs << m_Account << " " << m_Password << endl;  // ���˺ź�����д���ļ�
    ofs.close();  // �ر��ļ���
    cout << endl;
    cout << "���ѳɹ�ע��" << endl;
}
