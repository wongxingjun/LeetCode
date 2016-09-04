class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n,INT_MAX), cur(primes.size(),0);
        res[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<primes.size();j++)
            {
                if(primes[j]*res[cur[j]]==res[i-1])
                    cur[j]++;
                res[i]=min(res[i],primes[j]*res[cur[j]]);
            }
        }
        return res[n-1];
    }
};
