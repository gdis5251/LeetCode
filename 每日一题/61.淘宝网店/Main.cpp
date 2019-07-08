// write your code here cpp
#include <iostream>
#include <cmath>

bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool IsPrimeNumber(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int GetMoneyOfMonth(int year, int month)
{
    int ans = 0;
    bool leap_year = IsLeapYear(year);

    switch (month)
    {
    case 3:
    case 5:
    case 7:
        ans = 31;
        break;
    case 1:
    case 8:
    case 10:
    case 12:
        ans = 31 * 2;
        break;
    case 4:
    case 6:
    case 9:
        ans = 30 * 2;
        break;
    case 11:
        ans = 30;
        break;
    case 2:
        if (leap_year)
        {
            ans = 29;
        }
        else
        {
            ans = 28;
        }
        break;
    default:
        break;
    }

    return ans;
}

int GetDaysOfMonth(int year, int month)
{
    int ans = 0;
    bool leap_year = IsLeapYear(year);

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        ans = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        ans = 30;
        break;
    case 2:
        if (leap_year)
        {
            ans = 29;
        }
        else
        {
            ans = 28;
        }
        break;
    default:
        break;
    }

    return ans;
}

int main(void)
{
    int cur_year = 0;
    int cur_month = 0;
    int cur_day = 0;

    int end_year = 0;
    int end_month = 0;
    int end_day = 0;

    std::cin >> cur_year >> cur_month >> cur_day >> end_year >> end_month >> end_day;
    int sum = 0;
    if (cur_year == end_year)
    {
        bool prime = IsPrimeNumber(cur_month);
        if (cur_month == end_month)
        {
            sum += (end_day - cur_day + 1);
            if (!prime)
            {
                sum *= 2;
            }

            std::cout << sum << std::endl;
            return 0;
        }
        else
        {
            int day = GetDaysOfMonth(cur_year, cur_month);
            sum += day - cur_day + 1;
            if (!prime)
            {
                sum *= 2;
            }

            cur_month++;
        }
    }
    else
    {
        bool prime = IsPrimeNumber(cur_month);
        int day = GetDaysOfMonth(cur_year, cur_month);
        sum += day - cur_day + 1;
        if (!prime)
        {
            sum *= 2;
        }

        cur_month++;
    }
    while (cur_year <= end_year)
    {
        if (cur_year == end_year)
        {
            while (cur_month < end_month)
            {
                sum += GetMoneyOfMonth(cur_year, cur_month);
                cur_month++;
            }
            // 走到这月份已经相同
            if (IsPrimeNumber(cur_month))
            {
                sum += end_day;
            }
            else
            {
                sum += end_day * 2;
            }
        }
        else
        {
            while (cur_year < end_year)
            {
                if (13 == cur_month)
                {
                    cur_year++;
                    cur_month = 1;
                    break;
                }
                sum += GetMoneyOfMonth(cur_year, cur_month);
                cur_month++;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}