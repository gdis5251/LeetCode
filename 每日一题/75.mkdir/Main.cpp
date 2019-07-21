#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void PrintCommand(std::vector<std::string>& command)
{
    std::sort(command.begin(), command.end());
    std::vector<bool> flag(command.size(), true);

    for (int i = 0; i < command.size() - 1; i++)
    {
        // 如果两个命令相同，则把 第 i 个命令标记成 false
        if (command[i] == command[i + 1])
        {
            flag[i] = false;
        }
        else
        {
            // 如果前一个命令是后一个的子串
            if (command[i].size() < command[i + 1].size() && \
                command[i] == command[i + 1].substr(0, command[i].size()) && \
                command[i + 1][command[i].size()] == '/')
            {
                flag[i] = false;
            }
        }
    }

    for (int i = 0; i < command.size(); i++)
    {
        if (flag[i])
        {
            std::cout << "mkdir -p " << command[i] << std::endl;
        }
    }
}

int main(void)
{
    int n = 0;
    while (std::cin >> n)
    {
        getchar();

        std::vector<std::string> command(n);

        for (int i = 0; i < n; i++)
        {
            std::getline(std::cin, command[i]);
        }

        PrintCommand(command);
        std::cout << std::endl;
    }

    return 0;
}
}
}
}
}
}
}
}
}
}
}
