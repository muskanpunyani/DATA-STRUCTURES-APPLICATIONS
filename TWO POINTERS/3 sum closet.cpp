Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 

Constraints:

    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4


**********************
class Solution {
public:
    // similar to 3 sum
    // time=0(n2)
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX; // difference,we want min diff
        sort(nums.begin(),nums.end());
        int j,k;
        for(int i=0;i<nums.size();i++)
        {
            j=i+1;
            k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(diff)) // if min diff
                {
                    diff=target-sum;
                }
                if(sum<target)
                {
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        // target - sum =diff , so target-diff is sum
        int ans=target-diff; // target-diff will be the sum of elements whose sum is near to target
        return ans;
    }
};
