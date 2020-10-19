Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
******************************************************************

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       
        int n=matrix.size();
         if(n==0)
        {
            return 0;
        }
        int m=matrix[0].size();
        
        int dp[n+1][m+1];  
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=matrix[i][j]-'0';
                if(dp[i][j] >ans)   // if 1 is in 1st row or 1st col
                {
                    ans=dp[i][j];
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(dp[i][j]==1)
                {
                int a=dp[i-1][j-1];
                int b=dp[i][j-1];
                int c=dp[i-1][j];
                
                dp[i][j]=min(min(a,b),c) + dp[i][j];
                    if(dp[i][j] > ans)
                    {
                        ans=dp[i][j];
                    }
                }
                
            }
        }
        return ans*ans; // ans is size of side,sizee of sqr will be ans*ans
        
    }
};
