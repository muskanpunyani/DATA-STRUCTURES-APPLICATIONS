ou are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.

**************************************************
class Solution {
public:
    // time=0(nm)
    /*
    push all 0 hts into queue and then apply bfs and change the unchanged entries
    */
    int x_dir[4]={0,1,0,-1};
    int y_dir[4]={1,0,-1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        queue<pair<int,pair<int,int>> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,{j,0}});
                }
                else{
                    ans[i][j]=-1;  // rest all ht keep as -1 initially
                }
            }
        }
        while(!q.empty())
        {
                pair<int,pair<int,int>> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second.first;
                int ht=p.second.second;
                for(int k=0;k<4;k++)
                {
                    int x1=x+x_dir[k];
                    int y1=y+y_dir[k];
                    if(x1>=0 && x1<n && y1>=0 && y1<m && ans[x1][y1]==-1){ // if ht of that index is not updated then update the ht
                    ans[x1][y1]=ht+1;
                    q.push({x1,{y1,ht+1}});
                   }
            
                }
            
        }
        return ans;
        
        
    }
};
