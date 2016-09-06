class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        if(m==0) return true;
        int indexs=0,indext=0;
        while(indext<n)
        {
            if(s[indexs]==t[indext])
            {
                indexs++;
                if(indexs==m)
                    return true;
            }
            indext++;
        }
        return false;
    }
};
