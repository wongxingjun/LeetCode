class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        grid[x][y] = '0';
        for(int dx=-1;dx<=1;dx++)
        {
            for(int dy=-1;dy<=1;dy++)
            {
                if(dx+dy==1||dx+dy==-1)
                {
                    int nx=x+dx,ny=y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1')
                        dfs(nx, ny, grid);
                }

            }
        }
        return;
    }
};