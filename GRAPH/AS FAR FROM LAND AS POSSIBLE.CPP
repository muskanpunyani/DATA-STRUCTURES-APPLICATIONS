Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

 

Example 1:

Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.

 

Note:

    1 <= grid.length == grid[0].length <= 100
    grid[i][j] is 0 or 1

**********************************************************************************************************************************


// we are doing bfs
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int zero=0;
        int one=0;  
        queue<pair<int,int>> q;   // queue of coordinates i.e row,col
     
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    zero++;
                }
                else{
                    one++;
                    q.push({i,j});  // put 1,put all land in the queue
                    grid[i][j]=-1;   // mark 1 as -1 i.e visited
                }
            }
        }
        if(zero==0 || one==0)   // if count of zero 0r one is 0 then return -1
        {
            return -1;
        }
       int level=1;
       int dist=q.size();
       while(q.empty()==false)
       {
           pair<int,int> p=q.front();
           q.pop();
           int i=p.first;
           int j=p.second;
           dist--;
           // fill the dist in 4 dirn for 0, dist will be the level no,i.e bfs for all 4 dirn
           if( i+1>=0 && i+1<n && j>=0 && j<n && grid[i+1][j]==0)
           {
              grid[i+1][j]=level;
              q.push({i+1,j});
           }
             if( i-1>=0 && i-1<n && j>=0 && j<n && grid[i-1][j]==0)
           {
              grid[i-1][j]=level;
              q.push({i-1,j});
           }
             if( i>=0 && i<n && j+1>=0 && j+1<n && grid[i][j+1]==0)
           {
              grid[i][j+1]=level;
              q.push({i,j+1});
           }
             if( i>=0 && i<n && j-1>=0 && j-1<n && grid[i][j-1]==0)
           {
              grid[i][j-1]=level;
              q.push({i,j-1});
           }
        if(dist==0)
        {
            dist=q.size();
            level++;
        }
       }
     int ans=INT_MIN;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(grid[i][j]!=-1)   // i.e 0 ones value (water)
                 ans=max(ans,grid[i][j]);
         }
     }
        return ans;
    }

        
    
};
