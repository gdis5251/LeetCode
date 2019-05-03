#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
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
            for (size_t i = 0; i < matrix.size(); i++)
            {
                ans.push_back(matrix[i][0]);
            }
            
            return ans;
        }
        
        int i = 0;
        int j = 0;
        int num = row * col;
        int count = 0;
        int step = 0;
        bool isPush = true;
        while (step < num)
        {
            if (isPush)
                ans.push_back(matrix[i][j]);
            
            if (i == 0 + count && j != col - 1 - count)
            {
                j++;
                step++;
                isPush = true;
            }
            else if (j == col - 1 - count && i != row - 1 - count)
            { 
                i++;
                step++;
                isPush = true;
            }
            else if (i == row - 1 - count && j != 0 + count)
            {
                j--;
                step++;
                isPush = true;
            }
            else if (j == 0 + count && i != 1 + count)
            {
                i--;
                step++;
                isPush = true;
            }
            else if (j == 0 + count && i == 1 + count)
            {
                count++;
                isPush = false;
            }
            
            
        }
        
        return ans;
    }
};


int main(void)
{
    vector<vector<int> > arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans;
    ans = Solution::spiralOrder(arr);

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
