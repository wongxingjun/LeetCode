class Solution {
public:
    vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxlen=1;
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        vector<vector<int>> cacheMax(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int len = dfs(i,j,matrix,n,m,cacheMax);
                maxlen=len>maxlen?len:maxlen;
            }
        }
        return maxlen;
    }
    
    int dfs(int x, int y, vector<vector<int>>& matrix, int n,int m, vector<vector<int>>& cacheMax)
    {
        if(cacheMax[x][y]!=0) return cacheMax[x][y];
        int maxlen=1;
        for(vector<int> d:dirs)
        {
            int nx=x+d[0], ny=y+d[1];
            if(nx<0||nx>=n||ny<0||ny>=m||matrix[nx][ny]<=matrix[x][y])
                continue;
            int len=1+dfs(nx,ny,matrix,n,m,cacheMax);
            maxlen=len>maxlen?len:maxlen;
        }
        cacheMax[x][y]=maxlen;
        return maxlen;
    }

};


//Time Limit Exceeded
//Pure DFS, waste some time for revisiting some nodes
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxlen=1;
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        vector<vector<int>> cacheMax(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int len = dfs(i,j,matrix,cacheMax);
                maxlen=len>maxlen?len:maxlen;
            }
        }
        return maxlen;
    }
    
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& cache)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxlen=1;
        for(int dx=-1; dx<=1; dx++)
        {
            for(int dy=-1; dy<=1; dy++)
            {
                if(dx+dy==1||dx+dy==-1)
                {
                    int nx=x+dx,ny=y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]>matrix[x][y])
                    {
                        int len=1+dfs(nx, ny, matrix, cache);
                        maxlen=len>maxlen?len:maxlen;
                    }
                }
            }
        }
        return maxlen;
    }
};