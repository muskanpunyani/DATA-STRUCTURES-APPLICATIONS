Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7
**********************************************************************************************************************

class Solution {
public:
    int memo[100000];
    int answer(vector<int>& nums,int target)
    {
        if(target==0)
        {
            return 1;
        }
        if(memo[target]!=-1)
        {
            return memo[target];
        }
       int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
                ans+=answer(nums,target-nums[i]);
            }
        }
        memo[target]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo,-1,sizeof(memo));
        return answer(nums,target);
    }
};
