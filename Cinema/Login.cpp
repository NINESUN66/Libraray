#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include"SignUp.h"
#include"Login.h"

int MAX_TRY_TIMES = 5;//��������Դ����

//��¼�˵�
void LoginMenu()
{
    cout << "\033[1;36m* * * * * * * * * *\033[0m" << endl;
    cout << "\033[1;36m* * * 1. ��¼ * * *\033[0m" << endl;
    cout << "\033[37m* * * 2. ע�� * * *\033[0m" << endl;
    cout << "\033[37m* * * * * * * * * *\033[0m" << endl;
}

//��½����
int Login()
{
    LoginMenu();  // ��ʾ��¼�˵�

    string m;
    int n = 0;
    while (cin >> m)
    {
        if (m == "1" || m == "2")  // ��������Ƿ�Ϊ "1" �� "2"
        {
            n = atoi(m.c_str());  // �������ַ���ת��Ϊ����
            break;
        }
        else
        {
            cout << "������������������" << endl;  // ��ʾ��Ч����Ĵ�����Ϣ
            system("pause");
            system("cls");
            LoginMenu();  // ������ʾ��¼�˵�
        }
    }

    if (n == 2)  // ���ѡ��ע��
    {
        AccPass temp;
        temp.SignUp();  // ����ע�ắ��
        system("pause");
        system("cls");
        Login();  // �ٴε��õ�¼����
    }

    //��ʼ��¼
    string account;
    string password;
    bool IsLogin = false;

    while (!IsLogin)
    {
        cout << "\033[1;33m�����������˺�:\033[0m" << endl;
        cin >> account;

        cout << "\033[1;33m��������������:\033[0m" << endl;
        password = "";
        char p;
        while (p = _getch())  // �ӿ���̨��ȡ�ַ���������ʾ����Ļ��
        {
            if (p == '\r') break;  // ������»س��������˳�ѭ��
            if (p == 8 && password != "")
            {
                cout << char(8) << " " << char(8);  // ����ϴ�������ַ�
                password.pop_back();  // �������ַ�����ɾ�����һ���ַ�
            }
            if (p >= 32)
            {
                if (p != 32) { password = password + p; cout << "*"; }  // �� '*' ���������е�ÿ���ַ�
            }
        }
        cout << endl;

        string Acc, Pass;
        int num = 0;
        vector<AP> Aparr;
        ifstream ifs;
        ifs.open("Account.txt", ios::in);
        while (ifs >> Acc && ifs >> Pass)  // ���ļ��ж�ȡ�˺ź������
        {
            AP temp(Acc, Pass);
            Aparr.push_back(temp);
            num++;
        }
        ifs.close();

        for (int i = 0; i < num; i++)
        {
            if (Aparr[i].m_Pa == password && Aparr[i].m_Ac == account)  // ���������˺ź������Ƿ���洢��ֵƥ��
            {
                IsLogin = true;
                cout << "\033[32m��½�ɹ���\033[0m" << endl;   //��½�ɹ�
                if (account == "123")
                {
                    //����Ա��¼
                    system("pause");
                    system("cls");
                    return 1;
                }
                else
                {
                    //ѧ����¼
                    system("pause");
                    system("cls");
                    return 0;
                }
            }
        }

        cout << "\033[31m�˺Ż�����������������룡\033[0m" << endl; 
        system("pause");
        system("cls");
        LoginMenu();
        MAX_TRY_TIMES--;
        if (MAX_TRY_TIMES <= 0) {
            cout << "\033[31m���Ե�¼�������࣬�����˳���\033[0m" << endl; 
            exit(0);
        }
    }

    return -1;
}
