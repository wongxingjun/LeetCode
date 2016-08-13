class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mpN,mpM;
        for(char i:ransomNote)
            mpN[i]++;
        for(char i:magazine)
            mpM[i]++;
        for(auto it=mpN.begin();it!=mpN.end();it++){
            if(mpM.find(it->first)==mpM.end())
                return false;
            else{
                if(mpM.find(it->first)->second<it->second)
                    return false;
            }
        }
        return true;
    }
};
