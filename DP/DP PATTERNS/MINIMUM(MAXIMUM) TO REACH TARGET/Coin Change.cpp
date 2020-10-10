You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

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

******************************************************************************************************

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[amount+1];
        for(int i=0;i<=amount;i++)
        {
            dp[i]=amount+1;  // here can also take INT_MAX,taken amount+1 to avoid int overflow
        }
      dp[0]=0;
        for(int j=1;j<=amount;j++)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(coins[i]<=j) // if coins less than amount
                {
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);  // either take the coin or dont
                }
            }
        }
        if(dp[amount]>amount)
        {
            return -1;
        }
        return dp[amount];
        
    }
};
