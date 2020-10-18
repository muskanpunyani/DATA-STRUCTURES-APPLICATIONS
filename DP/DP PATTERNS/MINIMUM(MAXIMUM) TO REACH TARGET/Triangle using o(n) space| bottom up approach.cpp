class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    
        int n=triangle.size();
        int dp[n+1];
       
        for(int i=0;i<n;i++)   // last row
        {
            dp[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)  // bottom up
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        
    
   int ans=dp[0];
        return ans;
}
    
};
