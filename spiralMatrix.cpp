class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int raws=matrix.size();
        if(raws==0)
            return res;
        int cols=matrix[0].size();
        if(cols==0)
            return res;
        int start=0;
        while(raws>start*2&&cols>start*2)
        {
            circle(matrix,start,res);
            start++;
        }
        return res;
    }
    
    void circle(vector<vector<int>>& matrix,int start,vector<int>& res)
    {
        int endx=matrix[0].size()-1-start;
        int endy=matrix.size()-1-start;
        
        for(int i=start;i<=endx;i++)
            res.push_back(matrix[start][i]);
        
        if(start<endy)
        {
            for(int i=start+1;i<=endy;i++)
                res.push_back(matrix[i][endx]);
        }
        
        if(start<endx&&start<endy)
        {
            for(int i=endx-1;i>=start;i--)
                res.push_back(matrix[endy][i]);
        }
        
        if(start<endx&&start<endy-1)
        {
            for(int i=endy-1;i>=start+1;i--)
                res.push_back(matrix[i][start]);
        }
    }
};
