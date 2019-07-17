class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        // 先让小的数组位 1 号数组
        if (len1 > len2)
        {
            nums1.swap(nums2);
            std::swap(len1, len2);
        }
        int maxl = len1;
        int minl = 0;
        int half_len = (len1 + len2 + 1) / 2;
        
        while (minl <= maxl)
        {
            int apart = (minl + maxl) / 2;
            int bpart = half_len - apart;
            
            // 说明 A 部分取大了，应该缩小
            if (apart > minl && nums1[apart - 1] > nums2[bpart])
            {
                maxl = apart - 1;
            }
            else if (apart < maxl && nums1[apart] < nums2[bpart - 1])
            {
                minl = apart + 1;
            }
            else
            {
                int left_max = 0;
                if (apart == 0) // 也就是说 A 的最小值都比 B 的最大值还大
                {
                    left_max = nums2[bpart - 1];
                }
                else if (bpart == 0) // A 最大的值比 B 最小的值还小
                {
                    left_max = nums1[apart - 1];
                }
                else 
                {
                    left_max = std::max(nums1[apart - 1], nums2[bpart - 1]);
                }
                if ((len1 + len2) % 2 != 0)
                {
                    return left_max;
                }
                
                int right_min = 0;
                if (apart == len1)
                {
                    right_min = nums2[bpart];
                }
                else if (bpart == len2)
                {
                    right_min = nums1[apart];
                }
                else
                {
                    right_min = std::min(nums1[apart], nums2[bpart]);
                }
                
                return (left_max + right_min) / 2.0;
            }
        }
        return 0.0;
    }
};