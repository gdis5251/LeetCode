class Solution {
public:
    static void reverse(string& s, int lhs, int rhs)
    {
        while (lhs < rhs)
        {
            swap(s[lhs++], s[rhs--]);
        }
    }
    
    string reverseWords(string s) {
        if (s.empty())
            return s;
        
        std::reverse(s.begin(), s.end());
        
        size_t space = 0;
        int b = 0;
        int e = -2;
        bool isContinue = true;
        while (isContinue)
        {
            if (space == 0)
                b = 0;
            else
                b = space + 1;
            
            space = s.find(' ', space);
                
            if (space == s.npos)
            {
                isContinue = false;
                e = s.size() - 1;
            }
            else
            {
                e = space - 1;
            }
            
            if (space == 0 || space == s.size() - 1 || s[space + 1] == ' ')
            {
                s.erase(space, 1);
                continue;
            }
            else
            {
                space++;
            }
            
            reverse(s, b, e);
        }
        
        return s;
    }
};