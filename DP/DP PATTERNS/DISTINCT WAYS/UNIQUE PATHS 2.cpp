A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

 

Constraints:

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.

*******************************************************************************************


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(); // row
        int m=obstacleGrid[0].size(); // col
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
        {
            return 0;
        }
        long int dp[n+1][m+1];
        int f1=0,f2=0;
        for(int i=m-1;i>=0;i--)   // last row
        {
            if(obstacleGrid[n-1][i]!=1 && f1==0)
            {
                dp[n-1][i]=1;
            }
            else{
                dp[n-1][i]=0;
                f1=1;            // any of val comes zero next all elem will be 0
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(obstacleGrid[i][m-1]!=1 && f2==0)
            {
                dp[i][m-1]=1;
            }
            else{
                dp[i][m-1]=0;
                f2=1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(obstacleGrid[i][j]!=1)
                {
                    dp[i][j]=dp[i][j+1]+dp[i+1][j];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        int ans=dp[0][0];
        return ans;
    }
};
