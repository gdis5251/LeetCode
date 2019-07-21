class Solution {
public:
    /**
     *      * @param m: An integer m denotes the size of a backpack
     *           * @param A: Given n items with size A[i]
     *                * @param V: Given n items with value V[i]
     *                     * @return: The maximum value
     *                          */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        if (A.empty())
        {
            return 0;
        }

        int row = A.size();
        std::vector<std::vector<int>> maxValue(row + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i - 1] > j)
                {
                    maxValue[i][j] = maxValue[i - 1][j];
                }
                else
                {
                    maxValue[i][j] = std::max(maxValue[i - 1][j - A[i - 1]] + V[i - 1], maxValue[i - 1][j]);
                }
            }
        }

        return maxValue[row][m];
    }
};
}
}
}
}
}
}
}
