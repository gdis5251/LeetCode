class Hanoi {
public:
    int chkStep(vector<int> arr, int n) {
        if (arr.size() == 0)
        {
            return -1;
        }
        
        return CheckStep(arr, n - 1, 1, 2, 3);
    }
    
    int CheckStep(std::vector<int>& arr, int cur,\
                  int left, int mid, int right)
    {
        if (cur == -1)
        {
            return 0;
        }
        // 如果此时最大块在中间 说明不是最优解
        if (arr[cur] == mid)
        {
            return -1;
        }
        // 如果此时最大块在最左边
        // 说明最大块还没有动，现在要判断前 n - 1 个盘子动了多少次
        else if (arr[cur] == left)
        {
            return CheckStep(arr, cur - 1, left, right, mid);
        }
        else
        {
            // 如果在最右边
            // 说明当前最大的块已经走完了需要 2^(n - 1)
            // 在判断前 n - 1 个块需要多少步
            int step = CheckStep(arr, cur - 1, mid, left, right);
            if (step == -1)
            {
                return -1;
            }
            
            return (1 << cur) + step;
        }
        
    }
};