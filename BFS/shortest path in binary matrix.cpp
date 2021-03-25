Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1



***********************************
class Solution {
public:
    /*
    1 0 0
    1 1 0
    1 1 0 =>firstcell is only 1,1 ,can't traverse further
    */
   // time=0(n); bfs
    int x[8]={0,0,1,-1,1,-1,-1,1}; // 8 dirn
    int y[8]={1,-1,0,0,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});  // start index
        int level=1;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                if(p.first==n-1 && p.second==m-1) // found path
                {
                    return level;
                }
                for(int k=0;k<8;k++) // 8 dirn
                {
                    int x1=x[k]+p.first;
                    int y1=y[k]+p.second;
                    if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]==0) // if 0 then path
                    {
                        grid[x1][y1]=1;  // making it 1 bcz then it will be marked as visited and thus we will not take this again
                        q.push({x1,y1});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
