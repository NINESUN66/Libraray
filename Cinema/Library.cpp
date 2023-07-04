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

//���ͼ��
void Library::Book_In()
{
	string num;
	cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;
	cout << "\033[1;33m��������Ҫ��Ӽ����飺\033[0m" << endl;
	cin >> num;
	if (num == "*")
	{
		return;
	}
	//����鼮
	for (int Index = 0; Index < atoi(num.c_str()); Index++)
	{
		Book temp;
		cout << "\033[1;33m��" << Index + 1 << "���飺\033[0m" << endl;
		temp.Book_Set();

		//�������߳�����һ������Ϊͬһ����
		bool found = false; // ����Ƿ��ҵ�ƥ����鼮
		for (int i = 0; i < Lib.size(); i++)
		{
			if (temp.Get_Book_Author() == Lib[i].Get_Book_Author() && temp.Get_Book_Name() == Lib[i].Get_Book_Name() && temp.Get_Book_Publisher() == Lib[i].Get_Book_Publisher())
			{
				//����������Ŀ����
				Lib[i].Number_Add();
				found = true;
				break; // �ҵ�ƥ����鼮�������ڲ�ѭ��
			}
		}

		if (!found)
		{
			//������������
			Lib.push_back(temp);
			//�����鼮������
			Book_Kinds++;
		}
	}

}

//�������ͼ����Ϣ�Լ���������Ϣ
void Library::Book_Show()
{
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; }
	//��������鼮��Ϣ
	for (int i = 0; i < Book_Kinds; i++)
	{
		Lib[i].Book_Show();
	}
}

//����ͼ��
int Library::Book_Search()
{
	// ���ͼ���Ϊ�գ���ʾû��ͼ��Ĵ�����Ϣ��Ȼ�󷵻� -1
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return -1; }
	string n;
	cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;
	cout << "\033[32m�������������ݣ�\033[0m" << endl;
	cout << "\033[32m1->��������\033[0m" << endl;
	cout << "\033[32m2->ID����\033[0m" << endl;
	cout << "\033[32m3->��������\033[0m" << endl;
	cout << "\033[32m4->�������\033[0m" << endl;

	cin >> n;
	if (n == "*") return -1;  // ����û����� "*"���򷵻� -1
	if (n == "1")
	{
		string B_Name;
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl; 
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "��������������鼮���ƣ�";
		cin >> B_Name;  // �����û�������鼮����
		if (B_Name == "*")
		{
			system("cls");
			Book_Search();  // ���������µ��� Book_Search ������������
		}
		else
		{
			bool Is_Finded = false;  // ���ڱ���Ƿ��ҵ�ƥ����鼮
			for (int i = 0; i < Book_Kinds; i++)
			{
				if (B_Name == Lib[i].Get_Book_Name())  // ���������鼮������ͼ����е�ĳ���鼮����ƥ��
				{
					cout << "������£�" << endl;
					Lib[i].Book_Show();  // ��ʾƥ����鼮��Ϣ
					Is_Finded = true;  // ����ҵ���ƥ����鼮
					return i;  // ����ƥ����鼮��ͼ����е�����
				}
			}
			if (Is_Finded == false)
			{
				cout << "δ�ҵ�����,����������" << endl;
				Book_Search();  // ���µ��� Book_Search ������������
			}
		}
	}
	else if (n == "2")
	{
		string B_Id;
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "��������������鼮ID��";
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
					cout << "������£�" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "δ�ҵ�����,����������" << endl;
				Book_Search();
			}
		}
	}
	else if (n == "3")
	{
		string B_Author;
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "��������������鼮���ߣ�";
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
					cout << "������£�" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "δ�ҵ�����,����������" << endl;
				Book_Search();
			}
		}
	}
	else if (n == "4")
	{
		string B_Type;
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "��������������鼮���";
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
					cout << "������£�" << endl;
					Lib[i].Book_Show();
					Is_Finded = true;
					return i;
				}
			}
			if (Is_Finded == false)
			{
				cout << "δ�ҵ�����,����������" << endl;
				Book_Search();
			}
		}
	}
	else
	{
		cout << "�������,����������" << endl;
		Book_Search();
	}
	return -1;
}

//ɾ��ͼ��
void Library::Book_Delete()
{
	// ���ͼ���Ϊ�գ���ʾû��ͼ��Ĵ�����Ϣ��Ȼ�󷵻�
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; } 

	cout << "���������ɾ�����鼮" << endl;
	int Index = Book_Search();  // ���� Book_Search ���������鼮����ȡ������
	if (Index == -1) return;  // �������Ϊ -1���򷵻�

	string n;
	cout << "��ȷ��Ҫɾ����" << endl;
	cout << "1->ȷ��" << endl;
	cout << "2->ȡ��" << endl;
	while (cin >> n)
	{
		if (n == "1")
		{
			Lib.erase(Lib.begin() + Index);  // ��ͼ�����ɾ����Ӧ�������鼮
			Book_Kinds--;  // ͼ��������������
			return;
		}
		else if (n == "2")
		{
			cout << "ȡ���ɹ�" << endl;
			return;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
}

//�޸�ͼ��
void Library::Book_Change()
{
	// ���ͼ���Ϊ�գ���ʾû��ͼ��Ĵ�����Ϣ��������
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; }
	cout << "�������Ҫ�޸ĵ��鼮��";
	int Index = Book_Search();  // ���� Book_Search ���������鼮��������ȡƥ���鼮������
	if (Index == -1) return;  // ������ص�����Ϊ -1����ʾ�û�ȡ���˲�����ֱ�ӷ���
	Lib[Index].Book_Set();  // ���ߵ��� Book_Set ������ѡ�����鼮�����޸Ĳ���
}

//��������
bool cmp1(Book B1, Book B2)
{
	return B1.Get_Book_Name() > B2.Get_Book_Name();
}

//��������
bool cmp2(Book B1, Book B2)
{
	return B1.Get_Book_Name() < B2.Get_Book_Name();
}

//ID����
bool cmp3(Book B1, Book B2)
{
	return B1.Get_Book_Id() > B2.Get_Book_Id();
}

//ID����
bool cmp4(Book B1, Book B2)
{
	return B1.Get_Book_Name() < B2.Get_Book_Name();
}

//��������
bool cmp5(Book B1, Book B2)
{
	return B1.Get_Book_Rent_Time() < B2.Get_Book_Rent_Time();
}

//��������
bool cmp6(Book B1, Book B2)
{
	return B1.Get_Book_Rent_Time() > B2.Get_Book_Rent_Time();
}

//ͼ������
void Library::Book_Sort()
{
	// ���ͼ���Ϊ�գ���ʾû��ͼ��Ĵ�����Ϣ��������
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; }
	cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
	cout << "\033[1;36m----------------------\033[0m" << endl;

	cout << "\033[32m�������������ݣ�\033[0m" << endl;
	cout << "\033[32m1->��������\033[0m" << endl;
	cout << "\033[32m2->ID����\033[0m" << endl;
	cout << "\033[32m3->�ȶ�����\033[0m" << endl;
	string Choice;
	cin >> Choice;
	if (Choice == "*") return;  //�������Ϊ*��ʾ�û�ȡ����������������
	if (Choice == "1")
	{
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m����Ҫ�����ǽ���:\033[0m" << endl;
		cout << "\033[32m1->����\033[0m" << endl;
		cout << "\033[32m2->����\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }  // ����û����� "*"�������������µ��� Book_Sort ����
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp2);  // �� Lib ����������������ʹ�� cmp2 ������Ϊ�ȽϺ���
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp1);  // �� Lib �������н�������ʹ�� cmp1 ������Ϊ�ȽϺ���
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
	}
	else if (Choice == "2")
	{
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m����Ҫ�����ǽ���:\033[0m" << endl;
		cout << "\033[32m1->����\033[0m" << endl;
		cout << "\033[32m2->����\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp4);
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp3);
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
	}
	else if (Choice == "3")
	{
		cout << "\033[1;36m��*������һ���˵�\033[0m" << endl;
		cout << "\033[1;36m----------------------\033[0m" << endl;
		cout << "\033[32m����Ҫ�����ǽ���:\033[0m" << endl;
		cout << "\033[32m1->����\033[0m" << endl;
		cout << "\033[32m2->����\033[0m" << endl;

		string n;
		cin >> n;
		if (n == "*") { system("cls"); Book_Sort(); }
		if (n == "1")
		{
			sort(Lib.begin(), Lib.end(), cmp6);
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
		else if (n == "2")
		{
			sort(Lib.begin(), Lib.end(), cmp5);
			cout << "\033[32m����ɹ���\033[0m" << endl;
		}
	}
	else
	{
		cout << "\033[31m�����������������룡\033[0m" << endl;
		system("pause");
		system("cls");
		Book_Sort();
	}
}

//ͼ�����
void Library::Book_Rent()
{
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; }
	cout << "����������Ҫ���ĵ�ͼ��" << endl;
	int Index = Book_Search();
	if (Index == -1) { return; }
	else if (Lib[Index].Get_Book_Now_Number() > 0)  // �����ѡͼ��ĵ�ǰ�������� 0
	{
		Lib[Index].Rented();  // ִ��ͼ����Ĳ�����������ͼ����������
		Lib[Index].Renter_Add();  // ��������������һ
		cout << "\033[32m�ɹ����ģ�\033[0m" << endl;  // ��ʾ�ɹ����ĵ���Ϣ
	}
	else cout << "\033[31mû�����飬�����������\033[0m" << endl;
}

//ͼ��黹
void Library::Book_Return()
{
	if (Lib.empty() == true) { cout << "\033[31m��ǰ����û��ͼ��\033[0m" << endl; return; }
	cout << "����������Ҫ�黹����" << endl;
	int Index = Book_Search();
	if (Index == -1) return;	//û�ҵ�Ҫ�黹����
	
	if (Lib[Index].Get_Book_Now_Number() == Lib[Index].Get_Book_Number()) //�ҵ��˵���δ�����
	{
		cout << "\033[31m�ⲻ�Ǳ�ͼ��ݽ����ͼ�飬��ȷ��\033[0m" << endl;
	}
	else //�ɹ��黹
	{
		Lib[Index].Returned();
		cout << "\033[32m�ɹ��黹��\033[0m" << endl;
	}
}