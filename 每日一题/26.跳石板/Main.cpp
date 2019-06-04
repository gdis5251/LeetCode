#include <iostream>
#include <vector>
#include <algorithm>

void DivisorNum(int n, std::vector<int>& divisor_arr)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisor_arr.push_back(i);
            
            if (n / i != i)
                divisor_arr.push_back(n / i);
        }
    }
}

int Jump(int k, int m)
{
    // 先创建一个数组记录每种走法需要多少步
    std::vector<int> step_arr(m + 1, 0);
    step_arr[k] = 1;

    for (int i = k; i < m; i++)
    {
        // 先判断当前位置是否是以前可以到达的
        if (step_arr[i] == 0)
            continue;

        std::vector<int> divisor_arr;
        // 将当前数字的所有约数插入到约数数组里
        DivisorNum(i, divisor_arr);

        for (size_t j = 0; j < divisor_arr.size(); j++)
        {
            // 如果当前这个位置之前已经走到过了，然后取最小的
            if (divisor_arr[j] + i <= m && step_arr[divisor_arr[j] + i] != 0)
            {
                step_arr[divisor_arr[j] + i] = std::min(step_arr[divisor_arr[j] + i], step_arr[i] + 1);
            }
            else if (divisor_arr[j] + i <= m)
            {
                step_arr[divisor_arr[j] + i] = step_arr[i] + 1;
            }
        }
    }

    if (step_arr[m] == 0)
        return -1;

    return step_arr[m] - 1;
}

int main(void)
{
    int k = 0;
    int m = 0;

    while (std::cin >> k >> m)
    {
        int ans = Jump(k, m);
        
        std::cout << ans << std::endl;
    }

    return 0;
}
