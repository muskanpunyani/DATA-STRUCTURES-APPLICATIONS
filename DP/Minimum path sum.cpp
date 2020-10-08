Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

****************************************************************************************************************************


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();   // row
        int m=grid[0].size();  // col
        int dp[n+1][m+1];
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)  // fill 1st row
        {
            dp[0][i]=dp[0][i-1] + grid[0][i];
        }
        for(int j=1;j<n;j++)   // fill 1st col
        {
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];  // total min cost here
    }
};
