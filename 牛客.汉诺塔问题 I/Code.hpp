class Hanoi {
public:
    vector<string> getSolution(int n) {
        std::vector<std::string> hnoi;
        std::string a("left");
        std::string b("mid");
        std::string c("right");
        
        GetHnoiString(hnoi, n, a, b, c);
        
        return hnoi;
    }
    
    void GetHnoiString(std::vector<std::string>& hnoi, int n, std::string& a, std::string& b, std::string& c)
    {
        if (n == 1)
        {
            std::string tmp("move from ");
            tmp += a;
            tmp += " to ";
            tmp += c;
            
            hnoi.push_back(tmp);
        }
        else
        {
            GetHnoiString(hnoi, n - 1, a, c, b);
            
            std::string tmp("move from ");
            tmp += a;
            tmp += " to ";
            tmp += c;
            hnoi.push_back(tmp);
            
            GetHnoiString(hnoi, n - 1, b, a, c);
        }
    }
};