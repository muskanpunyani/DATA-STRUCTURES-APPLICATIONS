Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100

***************************************************************************************************************

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        if((total%2)!=0)
        {
            return false;
        }
        int subsetsum=(total/2);
        bool dp[n+1][subsetsum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=subsetsum;j++)
            {
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        { 
            int val=nums[i-1];
            for(int j=0;j<=subsetsum;j++)
            {
                if(val>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-val] || dp[i-1][j];
                }
            }
        }
        bool ans=dp[n][subsetsum];
        return ans;
    }
};
