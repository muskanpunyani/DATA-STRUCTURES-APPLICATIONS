Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*******************************************************************************************
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,int n,int m)
    {
        if(row>=n || col>=m || row<0 || col<0 || grid[row][col]=='0')  // base case
            return;
        
        grid[row][col]='0';  // make that 1 equals 0 so that it cant be visited again
        
        // recurse in 4 dirn
        dfs(row+1,col,grid,n,m);
        dfs(row-1,col,grid,n,m);
        dfs(row,col+1,grid,n,m);
        dfs(row,col-1,grid,n,m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)       // if size is 0,i.e no rows
        {
            return 0;
        }
        int n=grid.size();    // row
        int m=grid[0].size();  // col
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')  // if 1 is found in grid,apply dfs
                {
                    island++;
                    dfs(i,j,grid,n,m);  
                }
            }
        }
        return island;
        
    }
};
