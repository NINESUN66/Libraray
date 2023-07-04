#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Renter
{
	//借阅人
	string Renter_Name;
	//借阅日期(后期添加时间以获取当前日期)
	int Rent_Year;
	int Rent_Month;
	int Rent_Day;
	//借阅时长
	int Rent_Time;
	//是否归还
	bool Is_Return;
	//归还日期
	int Return_Year;
	int Return_Month;
	int Return_Day;
public:
	Renter();
	void Return_DDL();
	void Renter_Set();
	void Renter_Show();
};

class Book:public Renter
{
private:
	//书名
	string Book_Name;
	//书ID
	string Book_Id;
	//书作者
	string Book_Author;
	//书出版社
	string Book_Publisher;
	//书籍类别
	string Book_Type;
	//是否借阅
	bool Is_Rent;
	//每种书的数量(有这本书最少是1本)
	int Book_Number;
	//每种书的现有数量
	int Book_Now_Number;
	//借阅次数
	int Rent_Times;
	//借阅人信息
	vector<Renter> Book_Renter;
public:
	Book();
	//信息录入
	void Book_Set();
	//信息展示
	void Book_Show();
	//借书
	void Rented();
	//还书
	void Returned();
	//书数量增加
	void Number_Add();
	//书数量减少
	void Number_Reduce();
	//增加借阅人信息数组
	void Renter_Add();
	//获取单个信息的接口
	string Get_Book_Name();
	string Get_Book_Id();
	string Get_Book_Author();
	string Get_Book_Publisher();
	string Get_Book_Type();
	int Get_Book_Rent_Time();
	int Get_Book_Number();
	int Get_Book_Now_Number();
};

class Library:public Renter,public Book
{
public:
	//构造函数创建结构体数组
	Library();
	//书籍录入
	void Book_In();
	//书籍搜索
	int Book_Search();
	//书籍删除
	void Book_Delete();
	//书籍修改
	void Book_Change();
	//书籍借阅
	void Book_Rent();
	//书籍排序（书名，作者名，ID）
	void Book_Sort();
	//书籍展示
	void Book_Show();
	//书籍归还
	void Book_Return();

	//保存并退出（未实现）
	void Book_Save();
private:
	//书的数组
	vector<Book> Lib;
	//书的种类
	int Book_Kinds;
};
