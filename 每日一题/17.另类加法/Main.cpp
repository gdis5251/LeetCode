class UnusualAdd {
public:
    int addAB(int A, int B) {
        if (A == 0)
            return B;
        if (B == 0)
            return A;
        
        return addAB(A^B, (A&B) << 1);
    }
};
