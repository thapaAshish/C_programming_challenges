#include <iostream>
#include <array>
#include <vector>
using namespace std;

int monthNumbers[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 20, 31};
//leap year feb has 29 days
bool isLeapYear = false;
int findNextDay(int day, int month, int year)
{
    if (year % 4 == 0 and year % 100 != 0)
    {
        isLeapYear = true;
    }

    if (day < monthNumbers[month])
    {

        return day + 1;
    }
    else
    {
        if (isLeapYear and month == 2 and day < 29)
        {
            return day + 1;
        }
        else
        {
            return 1;
        }
    }
}

int findNextMonth(int month)
{
    if (month == 12)
    {
        return 1;
    }
    else
    {
        return month + 1;
    }
}
int main()
{
    int totalConsumption = 0;
    int nData;
    cin >> nData;
    int consecutiveDays = 0;
    int years[nData] = {0}, months[nData] = {0}, day[nData] = {0}, consumption[nData] = {0};
    for (int i = 0; i < nData; i++)
    {
        cin >> day[i] >> months[i] >> years[i] >> consumption[i];
        if (i > 0)
        {
            if (years[i] == years[i - 1] or years[i] == years[i - 1] + 1)
            {
                if (months[i] == months[i - 1] or months[i] == findNextMonth(months[i - 1]))
                {
                    if (findNextDay(day[i - 1], months[i - 1], years[i - 1]) == day[i])
                    {
                        // now increase the consecutive days
                        consecutiveDays++;
                        totalConsumption += consumption[i] - consumption[i - 1];
                    }
                }
            }
        }
    }
    cout << consecutiveDays << " " << totalConsumption << endl;
}
