#include"Class.h"
#include"Login.h"
#include"SignUp.h"
using namespace std;

//TODO: 1.����鼮��Ϣ���ڴ��д
//		2.���ͼ�ν���

//����Ա�˵�����
void MainMenu1()
{
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;33m  ******** \033[1;36m��ӭ����ͼ�����ϵͳ \033[1;33m********\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m1. �鼮¼�� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m2. �鼮���� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m3. �鼮ɾ�� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m4. �鼮�޸� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m5. �鼮���� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m6. �鼮չʾ \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m7. �鼮���� \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m8. �鼮�黹 \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  ************* \033[1;32m9. �˳�ϵͳ \033[1;34m*************\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
}
//ѧ���˵�����
void MainMenu2()
{
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;33m  *******��ӭ����һ��ͼ�����ϵͳ*******\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m1->�鼮����\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m2->�鼮����\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m3->�鼮չʾ\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m4->�鼮����\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m5->�鼮�黹\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;34m  **************\033[1;32m6->�˳�ϵͳ\033[1;34m*************\033[0m" << endl;
	cout << "\033[1;33m******************************************\033[0m" << endl;
}

int main()
{
	
	//ʵ����һ��ͼ���
	Library L1;
	//���˵�ѡ��
	string Choice;
	//����Ա��¼
	if (Login() == 1)
	{
		cout << "            ��ӭ����ͼ�����Ա��" << endl;
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
				cout << "\033[32m��л����ʹ�ã��ټ�\033[0m" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "\033[31m������������������\033[0m" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	//ѧ����¼
	else
	{
		cout << "               ��ӭ����ͬѧ��" << endl;
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
				cout << "\033[32m��л����ʹ�ã��ټ�\033[0m" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "\033[31m������������������\033[0m" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}