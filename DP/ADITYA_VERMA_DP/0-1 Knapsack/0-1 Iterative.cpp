
// time=0(n*W)=space
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // iterative solution
       int dp[n+1][W+1];
       
       // initialization
       // if n=0 W=0 ans would be 0
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0 || j==0)
               {
                   dp[i][j]=0;
               }
           }
       }
       // code
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=W;j++)
           {
               if(wt[i-1]<=j)  // if wt less than capacity
               {
                   // can consider or cannot
                   int opt1=dp[i-1][j];  // dont consider
                   int opt2=val[i-1] + dp[i-1][j-wt[i-1]]; // consider
                   dp[i][j]=max(opt1,opt2);
               }
               else{
                   // wt[i-1]>j , will not consider; wt greater than capacity
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};
