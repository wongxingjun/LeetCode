class Solution {
public:
    int nthUglyNumber(int n) {
        int l2 = 0, l3 = 0, l5 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            dp[i] = min(dp[l2]*2,min(dp[l3]*3,dp[l5]*5));
            if(dp[i] == dp[l2]*2) l2++; 
            if(dp[i] == dp[l3]*3) l3++;
            if(dp[i] == dp[l5]*5) l5++;
        }
        return dp[n-1];
    }
    
};
