class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        int ans = 0;
        
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    ans++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        
        return ans;
    }
    
private:
    int row;
    int col;
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            if (grid[i][j] == '1' && visited[i][j] == false)
            {
                visited[i][j] = true;
                bfs(grid, visited, i + 1, j);
                bfs(grid, visited, i - 1, j);
                bfs(grid, visited, i, j + 1);
                bfs(grid, visited, i, j - 1);

            }
        }
        else
            return;
    }
};