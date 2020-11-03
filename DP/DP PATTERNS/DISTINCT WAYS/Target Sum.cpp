You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

 

Constraints:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.

************************************************************************************************

class Solution {
public:
    int answer(vector<int>& nums,int sum,int i,int S,int dp[21][2001])
    {
        if(i==nums.size())
        {
            if(sum==S)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][sum+1000]!=-1)
        {
            return dp[i][sum+1000];
        }
          int add=  answer(nums,sum+nums[i],i+1,S,dp);  // 2 operations recursively
          int sub= answer(nums,sum-nums[i],i+1,S,dp);
          dp[i][sum+1000]=add+sub;
        return dp[i][sum+1000];
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        int i=0; // index;
        
        int dp[21][2001];
        memset(dp,-1,sizeof(dp));
        int count=answer(nums,sum,i,S,dp);
        return count;
    }
};
