You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Example 4:

Input: coins = [1], amount = 1
Output: 1

Example 5:

Input: coins = [1], amount = 2
Output: 2

 

Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104


*********************
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // minimum number of coins= coin change 2
        
        int n=coins.size();
        int dp[n+1][amount+1];
        
        // initialization
        // first row  will be infinity ;  n=0 amount>0, infinite coins required
        // first col will be 0 ; amount=0 , n>0 to make sum=0 then 0 coins minimum
        // n=0 sum=0 min coins=0
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0 && j>0)
                {
                    dp[i][j]=INT_MAX-1;
                }
                else if(j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
        // need to take 2nd row as well for initialization
        //for n=1, 2nd row any sum should be divided completely by arr 1st elem to have possible soln.
        for(int j=1;j<=amount;j++)
        {
            if((j%coins[0])==0)
            {
                // for n=1, i.e array's first element should divide sum completely
                dp[1][j]=(j/coins[0]);
            }
            else{
                dp[1][j]=INT_MAX-1;
            }
        }
        
        // knapsack logic in a diff way
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
};
