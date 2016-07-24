class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(rows>0&&cols>0)
        {
            int x=0;
            int y=cols-1;
            while(x<rows&&y>=0)
            {
                if(matrix[x][y]==target)
                    return true;
                else if(matrix[x][y]>target)
                    y--;
                else
                    x++;
            }
        }
        return false;
    }
};
