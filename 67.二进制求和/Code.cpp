class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        
        string ans;
        int jw = 0;
        if (a.size() > b.size())
        {
            string::reverse_iterator ait = a.rbegin();
            string::reverse_iterator bit = b.rbegin();
            
            
            while (bit != b.rend())
            {
                if (*ait == '1' && *bit == '1')
                {
                    *ait = jw + '0';
                    jw = 1;
                }
                else if ((*ait == '1' && *bit == '0') || (*ait == '0' && *bit == '1'))
                {
                    *ait = '1' + jw;
                    if (*ait == '1')
                        jw = 0;
                    if (*ait == '2')
                    {
                        jw = 1;
                        *ait = '0';
                    }
                }
                else
                {
                    *ait = jw + '0';
                    jw = 0;
                }
                
                bit++;
                ait++;
            }
            
            while (ait != a.rend())
            {
                if (jw == 1)
                {
                    *ait += 1;
                    if (*ait == '2')
                    {
                        *ait = '0';
                        jw = 1;
                    }
                    else
                    {
                        jw = 0;
                    }
                }
                else
                {
                    jw = 0;
                    break;
                }
                
                ait++;
            }
            
            if (jw == 1)
            {

                ans += '1';
                ans += a;
            }
            else 
                return a;
            
        }
        
        if (a.size() <= b.size())
        {
            string::reverse_iterator ait = a.rbegin();
            string::reverse_iterator bit = b.rbegin();
            
            
            while (ait != a.rend())
            {
                if (*ait == '1' && *bit == '1')
                {
                    *bit = jw + '0';
                    jw = 1;
                }
                else if ((*ait == '1' && *bit == '0') || (*ait == '0' && *bit == '1'))
                {
                    *bit = '1' + jw;
                    if (*bit == '1')
                        jw = 0;
                    if (*bit == '2')
                    {
                        jw = 1;
                        *bit = '0';
                    }
                }
                else
                {
                    *bit = jw + '0';
                    jw = 0;
                }
                
                ait++;
                bit++;
            }
            
             while (bit != b.rend())
            {
                if (jw == 1)
                {
                    *bit += 1;
                    if (*bit == '2')
                    {
                        *bit = '0';
                        jw = 1;
                    }
                    else
                    {
                        jw = 0;
                    }
                 }
                 else
                 {
                    jw = 0;
                    break;
                 }
                 
                 bit++;
            }
            
            if (jw == 1)
            {
                ans += '1';
                ans += b;
            }
            else 
                return b;
            
        }
        
        return ans;
    }
};