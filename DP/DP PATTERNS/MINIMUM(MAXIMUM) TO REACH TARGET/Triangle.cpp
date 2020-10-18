Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


**************************************************************************************************************************************
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    
        int n=triangle.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)   // initialize dp with max
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)   // 1st column
        {
            dp[i][0]=dp[i-1][0] + triangle[i][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<triangle[i].size();j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        
    
    int arr[100000];
    for(int i=0;i<n;i++)
    {
        arr[i]=dp[n-1][i];        
    }
    int ans=*min_element(arr,arr+n);  // min in last row is answer
    return ans;
}
    
};
