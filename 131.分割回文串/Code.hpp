class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(const std::string& s, int begin, int end)
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

    void BackTrace(std::string& s, std::vector<std::string>& cur, int lastindex)
    {
        int n = s.size();
        if (lastindex >= n)
        {
            ans.push_back(cur);
            return;

        }

        for (int i = lastindex; i < s.size(); i++)
        {
            if (isPalindrome(s, lastindex, i))
            {
                cur.push_back(s.substr(lastindex, i - lastindex + 1));
                BackTrace(s, cur, i + 1);
                cur.pop_back();

            }

        }

    }

    vector<vector<string>> partition(string s) {
        std::vector<std::string> cur;
        BackTrace(s, cur, 0);

        return ans;

    }

};
