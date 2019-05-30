class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        // 如果我方棋子大于对方棋子，就是我方获胜
        int me = 0;
        int enemy = 0;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 1)
                    me++;
                else if (board[i][j] == -1)
                    enemy++;
            }
        }
        
        if (me > enemy)
            return true;
        
        return false;
    }
};