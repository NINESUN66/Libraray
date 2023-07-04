#include"SignUp.h"
#include <fstream>
#include<iostream>
#include<conio.h>
using namespace std;

#define AP "Account.txt"  // 定义文件路径
string Password1 = "";
string Password2 = "";

void BuildPassword()
{
    Password1 = "";
    Password2 = "";
    cout << "请输入您的密码:";
    char p;
    while (p = _getch())  // 获取输入的字符，但不显示在屏幕上
    {
        if (p == '\r') break;  // 如果按下回车键，则退出循环
        if (p == 8 && Password1 != "")
        {
            cout << char(8) << " " << char(8);  // 清除上次输入的字符
            Password1.pop_back();  // 从密码字符串中删除最后一个字符
        }
        if (p >= 32)
        {
            if (p != 32) Password1 = Password1 + p;  // 将字符添加到密码字符串中
            cout << "*";  // 显示 '*' 代替密码字符
        }
    }
    cout << endl;
    cout << "请再次确认您的密码:";
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
    ofs.open(AP, ios::out | ios::app);  // 打开文件进行写入并将写入指针定位到文件末尾
    cout << "请输入您的账号:"; 
    string Account;
    cin >> m_Account;
    BuildPassword();  // 调用函数以获取用户输入的密码，并存储到 Password1 和 Password2 中

    if (Password1 != Password2)  // 检查两次输入的密码是否一致
    {
        cout << "两次密码不一致，请重新输入" << endl;
        BuildPassword();  // 重新获取密码
    }

    m_Password = Password1;  // 将 Password1 赋值给成员变量 m_Password
    ofs << m_Account << " " << m_Password << endl;  // 将账号和密码写入文件
    ofs.close();  // 关闭文件流
    cout << endl;
    cout << "您已成功注册" << endl;
}
