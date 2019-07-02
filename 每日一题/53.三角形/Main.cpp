#include <iostream>
#include <string>


std::string Add(std::string s1, std::string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    std::string res = "";
    int i, j, k , t = 0;
    for (i=len1-1, j=len2-1; i>=0 && j>=0; i--, j--) {
        k = (s1[i]-'0') + (s2[j] - '0') + t;
        res = (char)(k % 10 + '0') + res;
        t = k / 10;
    }
    while (i>=0) {
        k = (s1[i]-'0') + t;
        res = (char)(k % 10 + '0') + res;
        t = k / 10;
        i--;
    }
    while (j>=0) {
        k = (s2[j]-'0') + t;
        res = (char)(k % 10 + '0') + res;
        t = k / 10;
        j--;
    }
    if (t>0) {
        res = (char) (t + '0') + res;
    }
     
    return res;
}
 

bool Greater(std::string lhs, std::string rhs)
{
    int len1 = lhs.size();
    int len2 = rhs.size();
    
    if (len1 > len2)
    {
        return true;
    }
    else if (len1 < len2)
    {
        return false;
    }
    
    return lhs.compare(rhs) > 0;
}

int main(void)
{
    std::string a, b, c;
    
    while (std::cin >> a >> b >> c)
    {
        
        if (Greater(Add(a, b), c) && Greater(Add(a, c), b) && Greater(Add(b, c), a))
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}