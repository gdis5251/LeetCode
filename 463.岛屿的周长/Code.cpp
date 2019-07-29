class Solution {
public:
    int steps[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}  };

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& book, \
             int x, int y, int* length)
    {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size() ||
            book[x][y] == 1)
        {
            return;

        }

        book[x][y] = 1;

        if (grid[x][y] == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + steps[i][0];
                int ny = y + steps[i][1];

                if (!(nx >= 0 && nx < grid.size() &&
                      ny >= 0 && ny < grid[0].size()) || 
                    grid[nx][ny] == 0)
                {
                    (*length)++;

                }

            }

        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + steps[i][0];
            int ny = y + steps[i][1];

            dfs(grid, book, nx, ny, length);

        }


    }

    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty())
        {
            return 0;

        }

        std::vector<std::vector<int> > book(grid.size(), std::vector<int>(grid[0].size(), 0));
        int length = 0;

        dfs(grid, book, 0, 0, &length);

        return length;

    }

};
