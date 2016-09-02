class Solution {
public:
    char findTheDifference(string s, string t) {
        int chart[26];
        char res;
        memset(chart,0,sizeof(chart));
        for(int i=0;i<t.size();i++)
        {
            chart[t[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            chart[s[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(chart[i]!=0)
                res=i+'a';
        }
        return res;
    }
};
