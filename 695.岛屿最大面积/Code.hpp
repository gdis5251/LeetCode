class Solution {
public:
    int max_area = 0;

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& book, int x, int y)
    {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size() ||
            grid[x][y] == 0 || book[x][y] == 1)
        {
            return 0;

        }

        book[x][y] = 1;

        return 1 + dfs(grid, book, x + 1, y) + dfs(grid, book, x - 1, y) + dfs(grid, book, x, y + 1) + dfs(grid, book, x, y - 1);

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
        {
            return 0;

        }

        std::vector<std::vector<int>> book(grid.size(), std::vector<int>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && book[i][j] == 0)
                {
                    max_area = std::max(max_area, dfs(grid, book, i, j));

                }

            }

        }

        return max_area;

    }

};
