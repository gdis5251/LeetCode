#include <iostream>
#include <vector>

void Shuffle(std::vector<int>& arr, int k)
{
    std::vector<int> after(arr.size());
    for (int i = 0; i < k; i++)
    {
        int left = 0;
        int right = (int)arr.size() / 2;
        int pos = 0;
        
        // 一左一右往after里面放
        while (left < (int)arr.size() / 2)
        {
            after[pos++] = arr[left++];
            after[pos++] = arr[right++];
        }
        
        arr = after;
    }
}

int main(void)
{
    int t = 0;
    std::cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        int k = 0;
        
        std::cin >> n >> k;
        
        std::vector<int> in_arr;
        in_arr.resize(2 * n);
        for (int j = 0; j < 2 * n; j++)
        {
            std::cin >> in_arr[j];
        }
        
        Shuffle(in_arr, k);

        for (size_t pos = 0; pos < in_arr.size(); pos++)
        {
            std::cout << in_arr[pos];
            if (pos == in_arr.size() - 1)
                break;
            
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}