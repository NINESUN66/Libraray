#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include"SignUp.h"
#include"Login.h"

int MAX_TRY_TIMES = 5;//定义最大试错次数

//登录菜单
void LoginMenu()
{
    cout << "\033[1;36m* * * * * * * * * *\033[0m" << endl;
    cout << "\033[1;36m* * * 1. 登录 * * *\033[0m" << endl;
    cout << "\033[37m* * * 2. 注册 * * *\033[0m" << endl;
    cout << "\033[37m* * * * * * * * * *\033[0m" << endl;
}

//登陆函数
int Login()
{
    LoginMenu();  // 显示登录菜单

    string m;
    int n = 0;
    while (cin >> m)
    {
        if (m == "1" || m == "2")  // 检查输入是否为 "1" 或 "2"
        {
            n = atoi(m.c_str());  // 将输入字符串转换为整数
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;  // 显示无效输入的错误消息
            system("pause");
            system("cls");
            LoginMenu();  // 重新显示登录菜单
        }
    }

    if (n == 2)  // 如果选择注册
    {
        AccPass temp;
        temp.SignUp();  // 调用注册函数
        system("pause");
        system("cls");
        Login();  // 再次调用登录函数
    }

    //开始登录
    string account;
    string password;
    bool IsLogin = false;

    while (!IsLogin)
    {
        cout << "\033[1;33m请输入您的账号:\033[0m" << endl;
        cin >> account;

        cout << "\033[1;33m请输入您的密码:\033[0m" << endl;
        password = "";
        char p;
        while (p = _getch())  // 从控制台获取字符，但不显示在屏幕上
        {
            if (p == '\r') break;  // 如果按下回车键，则退出循环
            if (p == 8 && password != "")
            {
                cout << char(8) << " " << char(8);  // 清除上次输入的字符
                password.pop_back();  // 从密码字符串中删除最后一个字符
            }
            if (p >= 32)
            {
                if (p != 32) { password = password + p; cout << "*"; }  // 用 '*' 代替密码中的每个字符
            }
        }
        cout << endl;

        string Acc, Pass;
        int num = 0;
        vector<AP> Aparr;
        ifstream ifs;
        ifs.open("Account.txt", ios::in);
        while (ifs >> Acc && ifs >> Pass)  // 从文件中读取账号和密码对
        {
            AP temp(Acc, Pass);
            Aparr.push_back(temp);
            num++;
        }
        ifs.close();

        for (int i = 0; i < num; i++)
        {
            if (Aparr[i].m_Pa == password && Aparr[i].m_Ac == account)  // 检查输入的账号和密码是否与存储的值匹配
            {
                IsLogin = true;
                cout << "\033[32m登陆成功！\033[0m" << endl;   //登陆成功
                if (account == "123")
                {
                    //管理员登录
                    system("pause");
                    system("cls");
                    return 1;
                }
                else
                {
                    //学生登录
                    system("pause");
                    system("cls");
                    return 0;
                }
            }
        }

        cout << "\033[31m账号或密码错误，请重新输入！\033[0m" << endl; 
        system("pause");
        system("cls");
        LoginMenu();
        MAX_TRY_TIMES--;
        if (MAX_TRY_TIMES <= 0) {
            cout << "\033[31m尝试登录次数过多，程序退出！\033[0m" << endl; 
            exit(0);
        }
    }

    return -1;
}
