#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> input;
    std::vector<int> output;
    input.resize(4);
    output.resize(3);
    
    while (std::cin >> input[0] >> input[1] >> input[2] >> input[3])
    {
        output[0] = (input[0] + input[2]) / 2;
        output[1] = (input[1] + input[3]) / 2;
        output[2] = input[3] - output[1];
        
        std::cout << output[0] << " " << output[1] << " " << output[2] << std::endl;
    }
    return 0;
}