class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        vector<string> res;
        vector<vector<string>> digit(8);
        digit[0]={"a","b","c"};
        digit[1]={"d","e","f"};
        digit[2]={"g","h","i"};
        digit[3]={"j","k","l"};
        digit[4]={"m","n","o"};
        digit[5]={"p","q","r","s"};
        digit[6]={"t","u","v"};
        digit[7]={"w","x","y","z"};
        res=digit[digits[0]-'2'];
        for(int i=0;i<digits.size()-1;i++)
        {
            if(digits[i]<'2'||digits[i]>'9')
                return {};
            res=Descartes(res,digit[digits[i+1]-'2']);
        }
        return res;
    }
    
    vector<string> Descartes(vector<string> &a,vector<string> &b)
    {
        int na=a.size(),nb=b.size();
        string tmp="";
        vector<string> res;
        for(int i=0;i<na;i++)
        {
            for(int j=0;j<nb;j++)
            {
                tmp=a[i]+b[j];
                res.push_back(tmp);
            }
        }
        return res;
    }
};
