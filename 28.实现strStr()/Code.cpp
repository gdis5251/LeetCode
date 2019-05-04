class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        
        string::iterator hit = haystack.begin();
        string::iterator nit = needle.begin();
        while (hit != haystack.end())
        {
            nit = needle.begin();
            if (*hit == *nit)
            {
                string::iterator thit = hit;
                while (thit != haystack.end() && nit != needle.end())
                {
                    if (*thit++ != *nit++)
                        break;
                }
                if (thit == haystack.end() && nit != needle.end())
                    break;
                if (*(--nit) == *(--thit))
                    return hit - haystack.begin();
            }
            
            hit++;
        }
        return -1;
    }
};