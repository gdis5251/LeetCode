#include <iostream>
#include <string>
#include <unordered_map>

void Solution(std::string& lhs, std::string& rhs)
{
    std::unordered_map<char, int> hash_a;
    std::unordered_map<char, int> hash_b;
    
    for (const auto& ch : lhs)
    {
        hash_a[ch]++;
    }
    for (const auto& ch : rhs)
    {
        hash_b[ch]++;
    }
    
    for (const auto& ch : rhs)
    {
        if (hash_b[ch] > hash_a[ch])
        {
            std::cout << "No" << std::endl;
            return;
        }
    }
    
    std::cout << "Yes" << std::endl;
    return;
}

int main(void)
{
    std::string A;
    std::string B;
    
    while (std::cin >> A >> B)
    {
        Solution(A, B);
    }
    
    return 0;
}