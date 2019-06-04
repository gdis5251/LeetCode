#include <iostream>
#include <assert.h>

bool JudgeIsLeapYear(int year)
{
    assert(year > 0);
    
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    
    return false;
}

int getOutDay(int year, int month, int day)
{
    if (year < 0 || (month < 1 && month > 12) || day > 31)
        return -1;
    
    int sum = 0;
    
    for (int i = 1; i < month; i++)
    {
        switch(i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                sum += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                sum += 30;
                break;
            case 2:
                sum += 28;
                break;
            default:
                return -1;
        }
    }
    
    sum += day;
    if (JudgeIsLeapYear(year))
        sum += 1;
    
    return sum;
}

int main(void)
{
    int year = 0;
    int month = 0;
    int day = 0;
    
    while (std::cin >> year >> month >> day)
    {
        int ans = getOutDay(year, month, day);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}