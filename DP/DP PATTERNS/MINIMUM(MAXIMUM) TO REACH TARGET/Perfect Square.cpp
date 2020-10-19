Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
****************************************************************************************


class Solution {
public:
    int result(int n,int dp[100000])
    {
      if(floor(sqrt(n))==ceil(sqrt(n)))  // if perfect square
      {
          return 1;
      }
        if(n<=3)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=n;
        for(int i=1;i<=n;i++)
        {
            int temp=i*i;
            if(temp>n)
            {
                break;
            }
            else{
                ans= min(1+result(n-temp,dp),ans);
            }
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=-1;
        }
        int ans=result(n,dp);
        return ans;
        
    }
};
