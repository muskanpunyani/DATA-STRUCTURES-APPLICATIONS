You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

 

Constraints:

    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000


***************
class Solution {
public:
    int countsubset(vector<int> & nums,int s)
    {
        int n=nums.size();
        int dp[n+1][s+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)  // j=0 to handle [0,0,0,0,0,1] arr
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       // subset sum diff = target, calculate how many such subset sum
        /*
        s1-s2 = target
        s1+ s2 =sum(arr)
        
    adding eqn 1 n 2
    2s1=target+sum(Arr)
    s1=target+sum(arr) / 2
    
    so need to find count of s1, that will be the count of difference of 2 subsets
    // problem reduced to count no of subsets with given sum
        */
        target=abs(target);
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int s1= (( target + sum)/2);
        if(sum < target || (sum+target)%2!=0)  // if sum is less than target , not possible for any ans to come
            return 0;
        return countsubset(nums,s1);
    }
};
