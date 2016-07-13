// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0)
            return n;
        int l=1,r=n;
        while(l<r)
        {
            //l+r may causes a overflow, so l+(r-l)/2 or use long long type will be safe.
            int mid=l+(r-l)/2; 
            int g=guess(mid);
            if(g==0)
                return mid;
            else if(g==1)
                l=mid;
            else
                r=mid;
        }
        return l;
    }
};
