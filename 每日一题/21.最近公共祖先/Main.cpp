class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        // 求两个从根结点开始的路径
        // 然后比较路径
        
        std::vector<int> pathA;
        std::vector<int> pathB;
        
        while (a != 1)
        {
            pathA.push_back(a);
            a /= 2;
        }
        pathA.push_back(1);
        
        while (b != 1)
        {
            pathB.push_back(b);
            b/=2;
        }
        pathB.push_back(1);

        std::reverse(pathA.begin(), pathA.end());
        std::reverse(pathB.begin(), pathB.end());
        
        int i = 0;
        int ans = 0;
        while (i < pathA.size() && i < pathB.size())
        {
            if (pathA[i] == pathB[i])
                ans = pathA[i];
            else 
                break;
            i++;
        }
        
        return ans;
    }
};