#include <iostream>
#include <vector>


void GetTriangle(std::vector<std::vector<int>>& arr)
{
    arr[0].resize(1);
    arr[0][0] = 1;
    
    for (size_t i = 1; i < arr.size(); i++)
    {
        arr[i].resize(arr[i - 1].size() + 2);
        for (size_t j = 0; j < arr[i].size(); j++)
        {
            if (j == 0 || j == arr[i].size() - 1)
            {
                arr[i][j] = 1;
            }
            else
            {
                if (j - 2 >= 0 && j - 2 < arr[i - 1].size())
                {
                    arr[i][j] += arr[i - 1][j - 2];
                }
                if (j - 1 >= 0 && j - 1 < arr[i - 1].size())
                {
                    arr[i][j] += arr[i - 1][j - 1];
                }
                if (j  >= 0 && j < arr[i - 1].size())
                {
                    arr[i][j] += arr[i - 1][j];
                }
            }
        }
    }
}

int Locate(std::vector<std::vector<int> >& arr)
{
    for (size_t i = 0; i < arr[arr.size() - 1].size(); i++)
    {
        if (arr[arr.size() - 1][i] % 2 == 0)
            return i + 1;
    }
    
    return -1;
}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        std::vector<std::vector<int> > arr;
        arr.resize(n);
        
        // 把杨辉三角存进去
        GetTriangle(arr);
        
        int ans = Locate(arr);
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
