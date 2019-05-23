#include <iostream>
#include <vector>

int main(void)
{
    std::vector<unsigned int> input;
    input.resize(2);
    std::vector<char> table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'E', 'F'};
    
    while (std::cin >> input[0] >> input[1])
    {
        std::vector<char> ans;
       
        if (input[0] == 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }    

        if (input[0] < 0) // 如果是负数，就把这个数变成补码
            input[0] = ~input[0] + 1;

        while (input[0] != 0)
        {
            ans.push_back(table[input[0] % input[1]]);
            input[0] /= input[1];
        }
        
        for (int i = static_cast<int>(ans.size()) - 1; i >= 0; i--)
        {
            std::cout << ans[i];
        }
        std::cout << std::endl;
    } 
    return 0;
}
