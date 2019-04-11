#include "Solution.h"

int main(void)
{
    std::vector<std::vector<int> > matrix;
    matrix.resize(3);

    matrix[0] = {1, 2, 3};
    matrix[1] = {4, 5, 6};
    matrix[2] = {7, 8, 9};

    for (const auto& e : matrix)
    {
        for (const auto& i : e)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    Solution a;
    a.rotate(matrix);

    std::cout << "###################" << std::endl;
    for (const auto& e : matrix)
    {
        for (const auto& i : e)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
