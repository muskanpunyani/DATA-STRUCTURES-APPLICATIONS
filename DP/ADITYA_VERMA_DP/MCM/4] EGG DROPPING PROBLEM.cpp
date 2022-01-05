You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.

Example 2:

Input:
N = 2, K = 10
Output: 4

Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
// time=0(egg*(floor^2))
***********************************
int dp[101][10001];
    int solve(int egg,int f)
    {
         if(egg==1)
            return f;
        if(f==0 || f==1)  
            return f;
        
        if(dp[egg][f]!=-1)
        {
            return dp[egg][f];
        }
        int ans=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int opt1,opt2;
            if(dp[egg-1][k-1]!=-1)
                opt1=dp[egg-1][k-1];
            else
            opt1=superEggDrop(egg-1,k-1);  // case 1, egg break
            
            dp[egg-1][k-1]=opt1;
            
            if(dp[egg][f-k]!=-1)
                opt2=dp[egg][f-k];
            else
             opt2=superEggDrop(egg,f-k);   // case 2 egg didnt break
            
            dp[egg][f-k]=opt2;
            
            int temp=1+ max(opt1,opt2);  // 1 + as no of moves are increasing with every call ; max bcz we need to check worst case
            ans=min(temp,ans);  // min  bcz we need min moves in worst case
        }
        dp[egg][f]=ans;
        return ans;
    }
