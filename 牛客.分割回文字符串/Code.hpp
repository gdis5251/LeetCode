class Solution {
public:
    int minCut(string s) {
        if (s.empty())
        {
            return 0;

        }

        std::vector<int> dp(s.size() + 1, 0);
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i] = i - 1;

        }

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                // 1~j  F(j)    j + 1 ~ i 是回文，再切一次
                if (isPal(s, j, i - 1))
                {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[s.size()];
    }

    bool isPal(const std::string& s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }
};
}
}
}
}
}
}
}
}
