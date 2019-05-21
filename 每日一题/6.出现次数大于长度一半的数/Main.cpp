#include <iostream>
#include <map>
#include <vector>
#include <string>

int main(void)
{
    std::string nums;
    while (std::getline(std::cin, nums))
    {
        // 将字符数字插入到 vector 中
        std::vector<int> numbers;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != ' ')
            {
                numbers.push_back(nums[i] - '0');
            }
        }
        
        // 再维护一个哈希表来记录每个数字所对应出现的次数
        std::map<int, int> hash_table;
        for (size_t i = 0; i < numbers.size(); i++)
        {
            hash_table[numbers[i]]++;
        }
        
        auto hit = hash_table.begin();
        while (hit != hash_table.end())
        {
            if ((*hit).second >= static_cast<int>(numbers.size() / 2))
            {
                std::cout << (*hit).first << std::endl;
                break;
            }
            
            hit++;
        }
    }
    
    
    return 0;
}
