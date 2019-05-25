#include <iostream>

int box[1000][1000] = {0};

int main(void)
{
    int w, h;
    while (std::cin >> w >> h)
    {
        int ans = 0;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (box[i][j] == 0)
                {
                    ans++;
                    if (i + 2 < w)
                        box[i + 2][j] = -1;
                    if (j + 2 < h)
                        box[i][j + 2] = -1;
                }
            }
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
