#include <iostream>
#include <string>
#include <vector>

int step[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void Judge(const std::vector<std::vector<char>>& map)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (map[i][j] == '+' || map[i][j] == '*')
            {
                for (int k = 0; k < 8; k++)
                {
                    int count = 1;
                    int x = i + step[k][0];
                    int y = j + step[k][1];

                    while (x >= 0 && x < 20 && y >= 0 && y < 20 && map[i][j] == map[x][y])
                    {
                        count++;
                        x += step[k][0];
                        y += step[k][1];

                    }

                    if (count == 5)
                    {
                        std::cout << "Yes" << std::endl;
                        return;

                    }

                }

            }

        }

    }
    std::cout << "No" << std::endl;

}

int main(void)
{
    std::vector<std::vector<char> > map(20, std::vector<char>(20, 0));

    while (std::cin >> map[0][0])
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;

                }
                std::cin >> map[i][j];

            }

        }
        Judge(map);

    }



    return 0;

}
