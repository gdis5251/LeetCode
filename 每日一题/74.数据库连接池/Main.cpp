#include <iostream>
#include <vector>
#include <string>

int GetCapacity(std::vector<std::string>& req)
{
    int capacity = 0;
    int max_capacity = 0;

    for (int i = 0; i < req.size(); i++)
    {
        int pos = req[i].rfind(' ');
        std::string cur_req = req[i].substr(pos+1);

        if (cur_req == "connect")
        {
            capacity++;

        }
        else
        {
            capacity--;

        }

        if (capacity > max_capacity)
        {
            max_capacity = capacity;

        }

    }

    return max_capacity;

}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        std::vector<std::string> req(n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            std::getline(std::cin, req[i]);

        }

        int ans = GetCapacity(req);
        std::cout << ans << std::endl;

    }

    return 0;

}
