#include <iostream>
#include <string>
#include <stack>


using namespace std;

class Parenthesis {
public:
    static bool chkParenthesis(string A, int n) {
        // write code here
        if (A.empty())
            return true;
        
        stack<char> s;
        auto ait = A.begin();
        s.push(*ait);
        ait++;
        
        while (ait != A.end())
        {
            if (*ait == ')' && !s.empty())
            {
                s.pop();
                ait++;
            }
            else if (*ait == ')' && s.empty())
            {
                return false;
            }
            else if (*ait == '(')
            {
                s.push(*ait);
                ait++;
            }
            else if (*ait != '(' && *ait != ')')
                return false;
        }
        
        if (!s.empty())
            return false;
        
        return true;
    }
};

int main(void)
{
    string A("()()()");
    bool ans = Parenthesis::chkParenthesis(A, A.size());

    cout << ans << endl;
    return 0;
}
