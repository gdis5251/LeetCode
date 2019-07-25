#include <iostream>
#include <string>
#include <stack>
#include <queue>


int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        std::stack<int> s;

        std::string input;

        for (int i = 0; i < n; i++)
        {
            std::cin >> input;
            if (input.size() == 1)
            {
                if (input[0] >= '0' && input[0] <= '9')
                {
                    s.push(input[0] - '0');

                }
                else
                {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();


                    switch(input[0])
                    {
                    case '+':
                        s.push(left + right);
                        break;
                    case '-':
                        s.push(left - right);
                        break;
                    case '*':
                        s.push(left * right);
                        break;
                    case '/':
                        s.push(left / right);
                        break;
                    default:
                        break;

                    }

                }

            }
            else
            {
                s.push(atoi(input.c_str()));

            }

        }

        int ans = s.top();
        std::cout << ans << std::endl;

    }

    return 0;

}
