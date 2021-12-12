Given two string X and Y of length N and M respectively. The task is to find the length of the longest subsequence of string X which is a substring in sequence Y.

Example 1:

Input:
N = 4, M = 8
X = "abcd"
Y = "bacdbdcd"
Output: 3
Explanation: "acd" is the longest subsequence
             from string X present as a
             substring in string Y.

Example 2:

Input:
N = 1, M = 1
X = 'a'
Y = 'a'
Output: 1
Explanation: 'a' is the answer.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSubsequenceSubstring() which takes 4 arguments(string X, string Y, N and M) and returns the answer. 

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M).

Constraints:
1<= N, M <=103


*********************
int maxSubsequenceSubstring(string x, string y, int n, int m){
    //this is same as lcs juts a slight variation
    /*
    in lcs=>
    if x[i-1]==y[j-1] => 1 + lcs(i-1,j-1);
    if not equal => lcs(i-1,j )  // skip x's character 
    lcs (i,j-1)  // skip y's character => but this second case cannot be possible as we need y to be a substring
    so else will only have => lcs(i-1,j-1)
    
    and ans could be any subseq so need to find max in dp array
    */
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j];  // only skipping x not y as y needs to be substring
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
