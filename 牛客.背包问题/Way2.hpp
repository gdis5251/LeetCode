class Solution {
public:
    /**
     *      * @param m: An integer m denotes the size of a backpack
     *           * @param A: Given n items with size A[i]
     *                * @param V: Given n items with value V[i]
     *                     * @return: The maximum value
     *                          */
    int backPackII(int m, vector<int> &A, vector<int> &V) {

        if (A.empty())
        {
            return 0;

        }

        int row = A.size();
        std::vector<std::vector<int>> maxValue(m + 1, 0);

        for (int i = 1; i <= row; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (A[i - 1] > j)
                {
                    maxValue[j] = maxValue[j];

                }
                else
                {
                    maxValue[j] = std::max(maxValue[j - A[i - 1]] + V[i - 1], maxValue[j]);

                }

            }

        }

        return maxValue[m];

    }

};
