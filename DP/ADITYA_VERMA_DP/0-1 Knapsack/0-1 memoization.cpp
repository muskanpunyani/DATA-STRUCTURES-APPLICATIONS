class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    static int dp[1002][1002];  // memoization dp
    memset(dp,-1,sizeof(dp));
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // recursion code
       // 2 choices if wt is less than total W; can take that elem or not take
       // 1 choice if wt is  greater than W, don't take
       // need max values of max options
       
       if(n==0 || W==0) // if size of bag is 0 or no elements max ans  could be 0
       {
           return 0;
       }
       if(dp[n][W]!=-1)
       {
           return dp[n][W];
       }
       else{
       if(wt[n-1]<=W)
       {
           // 2 choices
           int opt1=val[n-1]+knapSack(W-wt[n-1],wt,val,n-1);  // consider element and add its value, subtract its weight; recures for rest
           
           // dont consider
           int opt2=knapSack(W,wt,val,n-1);
           
           return dp[n][W]= max(opt1,opt2);
       }
       else{
           // 1 choice ; dont consider
           return dp[n][W]=knapSack(W,wt,val,n-1);
       }
       }
    }
};
