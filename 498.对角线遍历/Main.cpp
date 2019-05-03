#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty())
            return ans;
        
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        
        if (row == 1)
        {
            return matrix[0];
        }
        
        if (col == 1)
        {
            for (int i = 0; i < row; i++)
            {
                ans.push_back(matrix[i][0]);
            }
            
            return ans;
        }
        
        int i = 0;
        int j = 0;
        while (i < row && j < col)
        {
            ans.push_back(matrix[i][j]);
            
            if ((i + j) % 2 == 0)
            {
                if (i == 0 && j != col - 1)
                    j++;
                else if (j == col - 1)
                {
                    i++;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if (i != row - 1 && j == 0)
                    i++;
                else if (i == row - 1)
                    j++;
                else
                {
                    j--;
                    i++;
                }
            }
        }
        
        return ans;
    }
};

int main(void)
{
    //vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    //vector<vector<int> > matrix = {{1, 2}, {3, 4}};
    vector<vector<int> > matrix = {{2, 5}, {8, 4}, {0, -1}};
    vector<int> ans;
    ans = Solution::findDiagonalOrder(matrix);

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
