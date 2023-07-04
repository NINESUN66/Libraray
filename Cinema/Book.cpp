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

//����ͼ����Ϣ
void Book::Book_Set()
{
	int Book_Num;
	cout << "\033[1;35m�������鼮����:\033[0m";
	cin >> Book_Name;
	cout << "\033[1;35m�������鼮����:\033[0m";
	cin >> Book_Author;
	cout << "\033[1;35m�������鼮ID:\033[0m";
	cin >> Book_Id;
	cout << "\033[1;35m�������鼮������:\033[0m";
	cin >> Book_Publisher;
	cout << "\033[1;35m�������鼮���:\033[0m";
	cin >> Book_Type;
	cout << "\033[1;35m�������鼮����:\033[0m";
	cin >> Book_Num;
	Book_Number = (Book_Num > 1 ? Book_Num : 1);
	//���ݽ�ֹ��ͼ��¼��ϵͳǰ����
}

//���ͼ����Ϣ
void Book::Book_Show()
{
	cout << "\033[1;34m�鼮���ƣ�\033[0m" << setw(20) << left << Book_Name << "\t"
		<< "\033[1;35m�鼮���ߣ�\033[0m" << setw(15) << left << Book_Author << "\t"
		<< "\033[1;36m�鼮ID��\033[0m" << setw(10) << left << Book_Id << "\t"
		<< "\033[1;33m�鼮���\033[0m" << setw(15) << left << Book_Type << "\t"
		<< "\033[1;32m�鼮�����磺\033[0m" << setw(15) << left << Book_Publisher << "\t"
		<< "\033[1;31m�鼮ʣ��������\033[0m" << Book_Number << "��" << endl;

	if (Is_Rent == false)
	{
		cout << "\033[32m��ͼ��δ����\033[0m" << endl;
	}
	else
	{
		//�����������Ϣ
		for (int i = 0; i < Book_Number - Book_Now_Number; i++)
		{
			Book_Renter[i].Renter_Show();
		}
	}
		
}

//ͼ�����
void Book::Rented()
{
	Is_Rent = true;
	Rent_Times++;
	Book_Now_Number--;
}

//ͼ��黹
void Book::Returned()
{
	Is_Rent = false;
	Book_Now_Number++;
}

//ͬ��ͼ����������
void Book::Number_Add()
{
	Book_Number++;
}

//ͬ��ͼ����������
void Book::Number_Reduce()
{
	Book_Number--;
}

//��ȡ����
string Book::Get_Book_Author()
{
	return Book_Author;
}

//��ȡID
string Book::Get_Book_Id()
{
	return Book_Id;
}

//��ȡ����
string Book::Get_Book_Name()
{
	return Book_Name;
}

//��ȡ������
string Book::Get_Book_Publisher()
{
	return Book_Publisher;
}

//��ȡ����
string Book::Get_Book_Type()
{
	return Book_Type;
}

//��ȡ���ʱ��
int Book::Get_Book_Rent_Time()
{
	return Rent_Times;
}

//��ȡͬ����ͼ������
int Book::Get_Book_Number()
{
	return Book_Number;
}

//����ͼ�������
void Book::Renter_Add()
{
	Renter temp;
	temp.Renter_Set();
	Book_Renter.push_back(temp);
}

//��ȡ����ͬ���������
int Book::Get_Book_Now_Number()
{
	return Book_Now_Number;
}