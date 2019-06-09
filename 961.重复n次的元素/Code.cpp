/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> umap;
        
        for (const auto& e : A)
        {
            umap[e]++;
        }
        
        for (const auto& e : umap)
        {
            if (e.second != 1)
                return e.first;
        }
        
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // 将数组排序，中间的元素一定是重复 N 次的元素
        sort(A.begin(), A.end());
        
        if (A[(A.size() / 2) - 1] == A[A.size() / 2] || 
            A[(A.size() / 2) + 1] == A[A.size() / 2])
            return A[A.size()/2];
        
        return A[(A.size() / 2) - 1];
    }
};