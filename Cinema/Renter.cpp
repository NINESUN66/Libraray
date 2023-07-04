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

// 判断是否为闰年
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取指定月份的天数
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

// 判断日期是否有效
bool isValidDate(int day, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth = getDaysInMonth(month, year);
    return (day <= daysInMonth);
}

// 添加指定天数
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

//自动计算归还时间
void Renter::Return_DDL()
{
    // 定义临时变量
    int day = Rent_Day, month = Rent_Month, year = Rent_Year;
    int numDays = Rent_Time;

    // 添加天数
    addDays(day, month, year, numDays);
    // 赋值给归还日期
    Return_Day = day; Return_Month = month; Return_Year = year;
}

//设置借阅者信息
void Renter::Renter_Set()
{
	cout << "\033[1;35m请输入借阅人：\033[0m";
	cin >> Renter_Name;
	cout << "\033[1;35m请输入借阅时间：(以空格隔断，例如:2023 01 01)\033[0m";
    //检测输入日期正确性
    while (true)
    {   
        cin >> Rent_Year;
    	cin >> Rent_Month;
	    cin >> Rent_Day;
        if (isValidDate(Rent_Day,Rent_Month, Rent_Year)) {
            break;
        }
        else {
            cout << "输入的日期无效，请重新输入。" << endl;
        }
    }
	cout << "\033[1;35m请输入借阅时长：\033[0m";
    //检测输入时间正确性
    while (true) {
        cin >> Rent_Time;
        if (Rent_Time >= 0) {
            break;
        }
        else {
            cout << "输入的天数无效，请重新输入。" << endl;
        }
    }

	Return_DDL();
}

//输出借阅者信息
void Renter::Renter_Show()
{
	cout << "\033[1;31m借阅人：\033[0m" << Renter_Name << "\t";
	cout << "\033[1;32m借阅时间" << Rent_Year << "年 " << Rent_Month << "月 " << Rent_Day << "日\033[0m\t";
	cout << "\033[1;33m借阅时长\033[0m" << Rent_Time << endl;
	cout << "\033[1;34m最晚归还时间" << Return_Year << "年 " << Return_Month << "月 " << Return_Day <<"日\033[0m" << endl;
}