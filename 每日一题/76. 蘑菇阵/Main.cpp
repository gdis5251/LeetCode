#include <iostream>
#include <vector>

double GetPro(const std::vector<std::vector<int> >& grid)
{
    if (grid[0][0] == 1)
    {
        return 0;
    }
        
    int row = grid.size();
    int col = grid[0].size();
    
    std::vector<std::vector<double> > dp(row, std::vector<double>(col, 0));
    dp[0][0] = 1.0;
    
    for (int i = 1; i < col; i++)
    {
        if (grid[0][i] == 1)
        {
            break;
        }
        dp[0][i] = dp[0][i - 1] * 0.5;
    }
    
    for (int i = 1; i < row; i++)
    {
        if (grid[i][0] == 1)
        {
            break;
        }
        dp[i][0] = dp[i - 1][0] * 0.5;
    }
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            dp[i][j] = dp[i - 1][j] * (j == col - 1 ? 1 : 0.5) + dp[i][j - 1] * (i == row - 1 ? 1 : 0.5);
            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    return dp[row - 1][col - 1];
}

int main(void)
{
    int n = 0;
    int m = 0;
    int num = 0;
    
    while (std::cin >> n >> m >> num)
    {
        if (num == 0)
        {
            printf("%.2f\n", 1.00);
            continue;
        }
        std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
        
        // 给格子里种下蘑菇
        for (int i = 0; i < num; i++)
        {
            int row = 0;
            int col = 0;
            std::cin >> row >> col;
            
            grid[row - 1][col - 1] = 1;
        }
        
        double pro = GetPro(grid);
        
        printf("%.2f\n", pro);
    }
    
    return 0;
}