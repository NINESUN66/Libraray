#include"Class.h"
#include<iomanip>
using namespace std;

Book::Book()
{
	Book_Number = 1;
	Is_Rent = false;
	Rent_Times = 0;
	Book_Now_Number = 1;
}

//设置图书信息
void Book::Book_Set()
{
	int Book_Num;
	cout << "\033[1;35m请输入书籍名称:\033[0m";
	cin >> Book_Name;
	cout << "\033[1;35m请输入书籍作者:\033[0m";
	cin >> Book_Author;
	cout << "\033[1;35m请输入书籍ID:\033[0m";
	cin >> Book_Id;
	cout << "\033[1;35m请输入书籍出版社:\033[0m";
	cin >> Book_Publisher;
	cout << "\033[1;35m请输入书籍类别:\033[0m";
	cin >> Book_Type;
	cout << "\033[1;35m请输入书籍数量:\033[0m";
	cin >> Book_Num;
	Book_Number = (Book_Num > 1 ? Book_Num : 1);
	//本馆禁止在图书录入系统前借阅
}

//输出图书信息
void Book::Book_Show()
{
	cout << "\033[1;34m书籍名称：\033[0m" << setw(20) << left << Book_Name << "\t"
		<< "\033[1;35m书籍作者：\033[0m" << setw(15) << left << Book_Author << "\t"
		<< "\033[1;36m书籍ID：\033[0m" << setw(10) << left << Book_Id << "\t"
		<< "\033[1;33m书籍类别：\033[0m" << setw(15) << left << Book_Type << "\t"
		<< "\033[1;32m书籍出版社：\033[0m" << setw(15) << left << Book_Publisher << "\t"
		<< "\033[1;31m书籍剩余数量：\033[0m" << Book_Number << "本" << endl;

	if (Is_Rent == false)
	{
		cout << "\033[32m该图书未出借\033[0m" << endl;
	}
	else
	{
		//输出借阅人信息
		for (int i = 0; i < Book_Number - Book_Now_Number; i++)
		{
			Book_Renter[i].Renter_Show();
		}
	}
		
}

//图书借阅
void Book::Rented()
{
	Is_Rent = true;
	Rent_Times++;
	Book_Now_Number--;
}

//图书归还
void Book::Returned()
{
	Is_Rent = false;
	Book_Now_Number++;
}

//同样图书数量增加
void Book::Number_Add()
{
	Book_Number++;
}

//同样图书数量减少
void Book::Number_Reduce()
{
	Book_Number--;
}

//获取作者
string Book::Get_Book_Author()
{
	return Book_Author;
}

//获取ID
string Book::Get_Book_Id()
{
	return Book_Id;
}

//获取书名
string Book::Get_Book_Name()
{
	return Book_Name;
}

//获取出版社
string Book::Get_Book_Publisher()
{
	return Book_Publisher;
}

//获取类型
string Book::Get_Book_Type()
{
	return Book_Type;
}

//获取借出时间
int Book::Get_Book_Rent_Time()
{
	return Rent_Times;
}

//获取同种书图书总数
int Book::Get_Book_Number()
{
	return Book_Number;
}

//增加图书借阅者
void Book::Renter_Add()
{
	Renter temp;
	temp.Renter_Set();
	Book_Renter.push_back(temp);
}

//获取现有同种书的数量
int Book::Get_Book_Now_Number()
{
	return Book_Now_Number;
}