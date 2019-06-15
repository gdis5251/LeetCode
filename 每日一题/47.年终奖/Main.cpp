class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (i == 0 && j == 0)
                {}
                else if (i == 0)
                {
                    board[i][j] += board[i][j - 1];
                }
                else if (j == 0)
                {
                    board[i][j] += board[i - 1][j];
                }
                else
                {
                    // 比较从该点的上面走下来和从该点的左边走过来的
                    // 谁的值大
                    int top = board[i - 1][j];
                    int left = board[i][j - 1];
                    
                    if (top > left)
                    {
                        board[i][j] += top;
                    }
                    else
                    {
                        board[i][j] += left;
                    }
                }
            }
        }
        
        return board[board.size() - 1][board[0].size() - 1];
    }
};