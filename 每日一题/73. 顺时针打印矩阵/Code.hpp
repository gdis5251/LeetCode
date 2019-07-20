class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        vector<int> ans;
        // 四个方向，分别是右下左上
        vector<vector<int> > step = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, j = -1, start = 0;
        
        while (true)
        {
            // 计算下一步要走的位置
            int a = i + step[start][0];
            int b = j + step[start][1];
            // 如果超出边界或者这个点已经被走过了，就换方向
            if (!(a >= 0 && a < n) || !(b >= 0 && b < m) || mat[a][b] == INT_MAX)
            {
                start = (start + 1) % 4;
            }
            
            i = i + step[start][0];
            j = j + step[start][1];
            ans.push_back(mat[i][j]);
            // 标记该点
            mat[i][j] = INT_MAX;
            
            if (ans.size() == (size_t)(n * m))
            {
                break;
            }
        }
        
        return ans;
    }
};