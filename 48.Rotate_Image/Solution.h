#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    void rotate(std::vector<std::vector<int> >& matrix)
    {
        std::vector<std::vector<int> > ans;

        size_t sz = matrix.size();
        ans.resize(sz);

        for (size_t i = 0; i < sz; i++)
        {
            size_t szIn = matrix[i].size();
            ans[i].resize(szIn, 0);

            for (size_t j = 0; j < szIn; j++)
            {
                ans[i][j] = matrix[j][i];
            }
        }

        for (size_t i = 0; i < ans.size(); i++)
        {
            reverse(ans[i].begin(), ans[i].end());
        }

        matrix = ans;
    }     
};
