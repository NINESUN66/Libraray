#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Renter
{
	//������
	string Renter_Name;
	//��������(�������ʱ���Ի�ȡ��ǰ����)
	int Rent_Year;
	int Rent_Month;
	int Rent_Day;
	//����ʱ��
	int Rent_Time;
	//�Ƿ�黹
	bool Is_Return;
	//�黹����
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
	//����
	string Book_Name;
	//��ID
	string Book_Id;
	//������
	string Book_Author;
	//�������
	string Book_Publisher;
	//�鼮���
	string Book_Type;
	//�Ƿ����
	bool Is_Rent;
	//ÿ���������(���Ȿ��������1��)
	int Book_Number;
	//ÿ�������������
	int Book_Now_Number;
	//���Ĵ���
	int Rent_Times;
	//��������Ϣ
	vector<Renter> Book_Renter;
public:
	Book();
	//��Ϣ¼��
	void Book_Set();
	//��Ϣչʾ
	void Book_Show();
	//����
	void Rented();
	//����
	void Returned();
	//����������
	void Number_Add();
	//����������
	void Number_Reduce();
	//���ӽ�������Ϣ����
	void Renter_Add();
	//��ȡ������Ϣ�Ľӿ�
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
	//���캯�������ṹ������
	Library();
	//�鼮¼��
	void Book_In();
	//�鼮����
	int Book_Search();
	//�鼮ɾ��
	void Book_Delete();
	//�鼮�޸�
	void Book_Change();
	//�鼮����
	void Book_Rent();
	//�鼮������������������ID��
	void Book_Sort();
	//�鼮չʾ
	void Book_Show();
	//�鼮�黹
	void Book_Return();

	//���沢�˳���δʵ�֣�
	void Book_Save();
private:
	//�������
	vector<Book> Lib;
	//�������
	int Book_Kinds;
};
