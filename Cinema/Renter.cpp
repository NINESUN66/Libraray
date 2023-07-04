#include"Class.h"
using namespace std;

Renter::Renter()
{
	Is_Return = false;
	Rent_Time = 0;
    Rent_Day = 0;
    Rent_Month = 0;
    Rent_Year = 0;
    Return_Month = 0;
    Return_Year = 0;
    Return_Day = 0;
}

// �ж��Ƿ�Ϊ����
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ��ȡָ���·ݵ�����
int getDaysInMonth(int month, int year)
{
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// �ж������Ƿ���Ч
bool isValidDate(int day, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth = getDaysInMonth(month, year);
    return (day <= daysInMonth);
}

// ���ָ������
void addDays(int& day, int& month, int& year, int numDays)
{
    while (numDays > 0) {
        int daysInMonth = getDaysInMonth(month, year);
        int daysToAdd = min(numDays, daysInMonth - day + 1);

        day += daysToAdd;
        numDays -= daysToAdd;

        if (day > daysInMonth) {
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            }
            else {
                month++;
            }
        }
    }
}

//�Զ�����黹ʱ��
void Renter::Return_DDL()
{
    // ������ʱ����
    int day = Rent_Day, month = Rent_Month, year = Rent_Year;
    int numDays = Rent_Time;

    // �������
    addDays(day, month, year, numDays);
    // ��ֵ���黹����
    Return_Day = day; Return_Month = month; Return_Year = year;
}

//���ý�������Ϣ
void Renter::Renter_Set()
{
	cout << "\033[1;35m����������ˣ�\033[0m";
	cin >> Renter_Name;
	cout << "\033[1;35m���������ʱ�䣺(�Կո���ϣ�����:2023 01 01)\033[0m";
    //�������������ȷ��
    while (true)
    {   
        cin >> Rent_Year;
    	cin >> Rent_Month;
	    cin >> Rent_Day;
        if (isValidDate(Rent_Day,Rent_Month, Rent_Year)) {
            break;
        }
        else {
            cout << "�����������Ч�����������롣" << endl;
        }
    }
	cout << "\033[1;35m���������ʱ����\033[0m";
    //�������ʱ����ȷ��
    while (true) {
        cin >> Rent_Time;
        if (Rent_Time >= 0) {
            break;
        }
        else {
            cout << "�����������Ч�����������롣" << endl;
        }
    }

	Return_DDL();
}

//�����������Ϣ
void Renter::Renter_Show()
{
	cout << "\033[1;31m�����ˣ�\033[0m" << Renter_Name << "\t";
	cout << "\033[1;32m����ʱ��" << Rent_Year << "�� " << Rent_Month << "�� " << Rent_Day << "��\033[0m\t";
	cout << "\033[1;33m����ʱ��\033[0m" << Rent_Time << endl;
	cout << "\033[1;34m����黹ʱ��" << Return_Year << "�� " << Return_Month << "�� " << Return_Day <<"��\033[0m" << endl;
}