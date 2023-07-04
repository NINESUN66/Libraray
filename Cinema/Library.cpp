#include"Class.h"
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
using namespace std;

Library::Library()
{
	vector<Book> Lib;
	Book_Kinds = 0;
}

//添加图书
void Library::Book_In()
{
	string num;
	cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;
	cout << "\033[1;33m请输入您要添加几本书：\033[0m" << endl;
	cin >> num;
	if (num == "*")
	{
		return;
	}
	//添加书籍
	for (int Index = 0; Index < atoi(num.c_str()); Index++)
	{
		Book temp;
		cout << "\033[1;33m第" << Index + 1 << "本书：\033[0m" << endl;
		temp.Book_Set();

		//书名作者出版社一样则视为同一本书
		bool found = false; // 标记是否找到匹配的书籍
		for (int i = 0; i < Lib.size(); i++)
		{
			if (temp.Get_Book_Author() == Lib[i].Get_Book_Author() && temp.Get_Book_Name() == Lib[i].Get_Book_Name() && temp.Get_Book_Publisher() == Lib[i].Get_Book_Publisher())
			{
				//增加已有书目数量
				Lib[i].Number_Add();
				found = true;
				break; // 找到匹配的书籍后跳出内层循环
			}
		}

		if (!found)
		{
			//加入新书数组
			Lib.push_back(temp);
			//更新书籍种类数
			Book_Kinds++;
		}
	}

}

//输出所有图书信息以及借阅者信息
void Library::Book_Show()
{
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; }
	//遍历输出书籍信息
	for (int i = 0; i < Book_Kinds; i++)
	{
		Lib[i].Book_Show();
	}
}

//搜索图书
int Library::Book_Search()
{
	// 如果图书馆为空，显示没有图书的错误消息，然后返回 -1
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return -1; }
	string n;
	cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;
	cout << "\033[32m请输入搜索依据：\033[0m" << endl;
	cout << "\033[32m1->书名搜索\033[0m" << endl;
	cout << "\033[32m2->ID搜索\033[0m" << endl;
	cout << "\033[32m3->作者搜索\033[0m" << endl;
	cout << "\033[32m4->类别搜索\033[0m" << endl;

	cin >> n;
	if (n == "*") return -1;  // 如果用户输入 "*"，则返回 -1
	if (n == "1")
	{
		string B_Name;
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl; 
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "请输入待搜索的书籍名称：";
		cin >> B_Name;  // 接收用户输入的书籍名称
		if (B_Name == "*")
		{
			system("cls");
			Book_Search();  // 清屏并重新调用 Book_Search 函数进行搜索
		}
		else
		{
			bool Is_Finded = false;  // 用于标记是否找到匹配的书籍
			for (int i = 0; i < Book_Kinds; i++)
			{
				if (B_Name == Lib[i].Get_Book_Name())  // 如果输入的书籍名称与图书馆中的某本书籍名称匹配
				{
					cout << "结果如下：" << endl;
					Lib[i].Book_Show();  // 显示匹配的书籍信息
					Is_Finded = true;  // 标记找到了匹配的书籍
					return i;  // 返回匹配的书籍在图书馆中的索引
				}
			}
			if (Is_Finded == false)
			{
				cout << "未找到该书,请重新输入" << endl;
				Book_Search();  // 重新调用 Book_Search 函数进行搜索
			}
		}
	}
	else if (n == "2")
	{
		string B_Id;
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "请输入待搜索的书籍ID：";
		cin >> B_Id;
		if (B_Id == "*")
		{
			system("cls");
			Book_Search();
		}
		else
		{
			bool Is_Finded = false;
			for (int i = 0; i < Book_Kinds; i++)
			{
				if (B_Id == Lib[i].Get_Book_Id())
				{
					cout << "结果如下：" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "未找到该书,请重新输入" << endl;
				Book_Search();
			}
		}
	}
	else if (n == "3")
	{
		string B_Author;
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "请输入待搜索的书籍作者：";
		cin >> B_Author;
		if (B_Author == "*")
		{
			system("cls");
			Book_Search();
		}
		else
		{
			bool Is_Finded = false;
			for (int i = 0; i < Book_Kinds; i++)
			{
				if (B_Author == Lib[i].Get_Book_Author())
				{
					cout << "结果如下：" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "未找到该书,请重新输入" << endl;
				Book_Search();
			}
		}
	}
	else if (n == "4")
	{
		string B_Type;
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "请输入待搜索的书籍类别：";
		cin >> B_Type;
		if (B_Type == "*")
		{
			system("cls");
			Book_Search();
		}
		else
		{
			bool Is_Finded = false;
			for (int i = 0; i < Book_Kinds; i++)
			{
				if (B_Type == Lib[i].Get_Book_Type())
				{
					cout << "结果如下：" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "未找到该书,请重新输入" << endl;
				Book_Search();
			}
		}
	}
	else
	{
		cout << "输入错误,请重新输入" << endl;
		Book_Search();
	}
	return -1;
}

//删除图书
void Library::Book_Delete()
{
	// 如果图书馆为空，显示没有图书的错误消息，然后返回
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; } 

	cout << "请查找您想删除的书籍" << endl;
	int Index = Book_Search();  // 调用 Book_Search 函数查找书籍并获取其索引
	if (Index == -1) return;  // 如果索引为 -1，则返回

	string n;
	cout << "您确定要删除吗？" << endl;
	cout << "1->确认" << endl;
	cout << "2->取消" << endl;
	while (cin >> n)
	{
		if (n == "1")
		{
			Lib.erase(Lib.begin() + Index);  // 从图书馆中删除对应索引的书籍
			Book_Kinds--;  // 图书种类数量减少
			return;
		}
		else if (n == "2")
		{
			cout << "取消成功" << endl;
			return;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
}

//修改图书
void Library::Book_Change()
{
	// 如果图书馆为空，显示没有图书的错误消息，并返回
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; }
	cout << "请查找需要修改的书籍：";
	int Index = Book_Search();  // 调用 Book_Search 函数进行书籍搜索，获取匹配书籍的索引
	if (Index == -1) return;  // 如果返回的索引为 -1，表示用户取消了操作，直接返回
	Lib[Index].Book_Set();  // 否者调用 Book_Set 函数对选定的书籍进行修改操作
}

//书名降序
bool cmp1(Book B1, Book B2)
{
	return B1.Get_Book_Name() > B2.Get_Book_Name();
}

//书名升序
bool cmp2(Book B1, Book B2)
{
	return B1.Get_Book_Name() < B2.Get_Book_Name();
}

//ID降序
bool cmp3(Book B1, Book B2)
{
	return B1.Get_Book_Id() > B2.Get_Book_Id();
}

//ID升序
bool cmp4(Book B1, Book B2)
{
	return B1.Get_Book_Name() < B2.Get_Book_Name();
}

//次数升序
bool cmp5(Book B1, Book B2)
{
	return B1.Get_Book_Rent_Time() < B2.Get_Book_Rent_Time();
}

//次数降序
bool cmp6(Book B1, Book B2)
{
	return B1.Get_Book_Rent_Time() > B2.Get_Book_Rent_Time();
}

//图书排序
void Library::Book_Sort()
{
	// 如果图书馆为空，显示没有图书的错误消息，并返回
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; }
	cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;

	cout << "\033[32m请输入排序依据：\033[0m" << endl;
	cout << "\033[32m1->书名排序\033[0m" << endl;
	cout << "\033[32m2->ID排序\033[0m" << endl;
	cout << "\033[32m3->热度排序\033[0m" << endl;
	string Choice;
	cin >> Choice;
	if (Choice == "*") return;  //如果输入为*表示用户取消操作，结束函数
	if (Choice == "1")
	{
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m您需要升序还是降序:\033[0m" << endl;
		cout << "\033[32m1->升序\033[0m" << endl;
		cout << "\033[32m2->降序\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }  // 如果用户输入 "*"，则清屏并重新调用 Book_Sort 函数
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp2);  // 对 Lib 容器进行升序排序，使用 cmp2 函数作为比较函数
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp1);  // 对 Lib 容器进行降序排序，使用 cmp1 函数作为比较函数
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
	}
	else if (Choice == "2")
	{
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m您需要升序还是降序:\033[0m" << endl;
		cout << "\033[32m1->升序\033[0m" << endl;
		cout << "\033[32m2->降序\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp4);
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp3);
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
	}
	else if (Choice == "3")
	{
		cout << "\033[1;36m按*返回上一级菜单\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m您需要升序还是降序:\033[0m" << endl;
		cout << "\033[32m1->升序\033[0m" << endl;
		cout << "\033[32m2->降序\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp6);
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp5);
			cout << "\033[32m排序成功！\033[0m" << endl;
		}
	}
	else
	{
		cout << "\033[31m输入有误请重新输入！\033[0m" << endl;
		system("pause");
		system("cls");
		Book_Sort();
	}
}

//图书借阅
void Library::Book_Rent()
{
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; }
	cout << "请搜索您需要借阅的图书" << endl;
	int Index = Book_Search();
	if (Index == -1) { return; }
	else if (Lib[Index].Get_Book_Now_Number() > 0)  // 如果所选图书的当前数量大于 0
	{
		Lib[Index].Rented();  // 执行图书借阅操作，将现有图书数量减少
		Lib[Index].Renter_Add();  // 借阅者数组增加一
		cout << "\033[32m成功借阅！\033[0m" << endl;  // 显示成功借阅的消息
	}
	else cout << "\033[31m没有余书，请过几天再来\033[0m" << endl;
}

//图书归还
void Library::Book_Return()
{
	if (Lib.empty() == true) { cout << "\033[31m当前馆内没有图书\033[0m" << endl; return; }
	cout << "请搜索您需要归还的书" << endl;
	int Index = Book_Search();
	if (Index == -1) return;	//没找到要归还的书
	
	if (Lib[Index].Get_Book_Now_Number() == Lib[Index].Get_Book_Number()) //找到了但是未借出过
	{
		cout << "\033[31m这不是本图书馆借出的图书，请确认\033[0m" << endl;
	}
	else //成功归还
	{
		Lib[Index].Returned();
		cout << "\033[32m成功归还！\033[0m" << endl;
	}
}