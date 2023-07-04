#include"Class.h"
#include"Login.h"
#include"SignUp.h"
using namespace std;

//TODO: 1.添加书籍信息的内存读写
//		2.添加图形界面

//管理员菜单界面
void MainMenu1()
{
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;33m  ******** \033[1;36m欢迎进入图书管理系统 \033[1;33m********\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m1. 书籍录入 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m2. 书籍搜索 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m3. 书籍删除 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m4. 书籍修改 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m5. 书籍排序 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m6. 书籍展示 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m7. 书籍借阅 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m8. 书籍归还 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m9. 退出系统 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
}
//学生菜单界面
void MainMenu2()
{
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;33m  *******欢迎进入一个图书管理系统*******\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m1->书籍搜索\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m2->书籍排序\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m3->书籍展示\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m4->书籍借阅\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m5->书籍归还\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m6->退出系统\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
}

int main()
{
	
	//实例化一个图书馆
	Library L1;
	//主菜单选项
	string Choice;
	//管理员登录
	if (Login() == 1)
	{
		cout << "            欢迎您，图书管理员！" << endl;
		while (1)
		{
			MainMenu1();
			cin >> Choice;
			if (Choice == "1")
			{
				L1.Book_In();
				system("pause");
				system("cls");
			}
			else if (Choice == "2")
			{
				int Index = L1.Book_Search();
				system("pause");
				system("cls");
			}
			else if (Choice == "3")
			{
				L1.Book_Delete();
				system("pause");
				system("cls");
			}
			else if (Choice == "4")
			{
				L1.Book_Change();
				system("pause");
				system("cls");
			}
			else if (Choice == "5")
			{
				L1.Book_Sort();
				system("pause");
				system("cls");
			}
			else if (Choice == "6")
			{
				L1.Book_Show();
				system("pause");
				system("cls");
			}
			else if (Choice == "7")
			{
				L1.Book_Rent();
				system("pause");
				system("cls");
			}
			else if (Choice == "8")
			{
				L1.Book_Return();
				system("pause");
				system("cls");
			}
			else if (Choice == "9")
			{
				cout << "\033[32m感谢您的使用，再见\033[0m" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "\033[31m输入有误，请重新输入\033[0m" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	//学生登录
	else
	{
		cout << "               欢迎您，同学！" << endl;
		while (1)
		{
			MainMenu2();
			cin >> Choice;
			if (Choice == "1")
			{
				int Index = L1.Book_Search();
				system("pause");
				system("cls");
			}
			else if (Choice == "2")
			{
				L1.Book_Sort();
				system("pause");
				system("cls");
			}
			else if (Choice == "3")
			{
				L1.Book_Show();
				system("pause");
				system("cls");
			}
			else if (Choice == "4")
			{
				L1.Book_Rent();
				system("pause");
				system("cls");
			}
			else if (Choice == "5")
			{
				L1.Book_Return();
				system("pause");
				system("cls");
			}
			else if (Choice == "6")
			{
				cout << "\033[32m感谢您的使用，再见\033[0m" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "\033[31m输入有误，请重新输入\033[0m" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}