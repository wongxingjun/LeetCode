class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size()==0)
            return 1;
        int former=b.back();
        b.pop_back();
        return powmod(superPow(a,b),10)*powmod(a,former)%1337;
    }
    
    int powmod(int a, int n)
    {
        int res=1;
        a%=1337;
        for(int i=0;i<n;i++)
            res=(res*a)%1337;
        return res;
    }
};