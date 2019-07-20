class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int left_max = 0;
        int right_max = 0;
        int ans = INT_MIN;
        
        right_max = GetMax(A, 0, n);
        
        for (int i = 1; i < n; i++)
        {
            if (i != 0)
            {
                // 取左部分最大值
                if (left_max < A[i - 1])
                {
                    left_max = A[i - 1];
                }
                
                // 判断右部分最大值是否需要更改
                if (right_max == A[i - 1])
                {
                    right_max = GetMax(A, i, n);
                }
            }
            if (ans < std::abs(left_max - right_max))
            {
                ans = std::abs(left_max - right_max);
            }
        }
        
        return ans;
    }
private:
    int GetMax(vector<int>& A, int begin, int end)
    {
        int max = INT_MIN;
        
        for (int i = begin; i < end; i++)
        {
            if (max < A[i])
            {
                max = A[i];
            }
        }
        
        return max;
    }
};