You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.


*************************************
class Solution {
public:
    /*
    we will use bfs
    push every rotten orange in queue
    make adjacent 1 to roten oranges to rotten orange
    if we get any fresh orange after processing,then return -1
    */
    // time=0(n)
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0; // keeping the track of number of fresh orange
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0) // if no fresh orange
            return 0;
        int minutes=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int k=0;k<4;k++) // make adjacent 1 as 2
                {
                    int x1=x[k]+p.first;
                    int y1=y[k]+p.second;
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1)
                    {
                        grid[x1][y1]=2;
                        q.push({x1,y1});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        if(fresh==0)  // fresh orange remaining in grid
        return minutes-1;
        
        return -1;
    }
};
