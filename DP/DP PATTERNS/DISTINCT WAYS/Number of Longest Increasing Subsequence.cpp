Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

Constraints:

    1 <= nums.length <= 2000
    -106 <= nums[i] <= 106

******************************************************************************************************


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int output[n+1];
        for(int i=0;i<n;i++)
        {
            output[i]=1;
        }
        
        for(int i=1;i<n;i++)  // finding lcs
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    output[i]=max(output[i],output[j]+1);
                }
            }
        }
       int maxi=*max_element(output,output+n);
        int ans=0;
        if(maxi==1)
        {
            return n;
        }
        int dp[n+1];
        for(int i=0;i<n;i++)
        {
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            if(output[i]==1)
            {
                dp[i]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
               if(nums[i]>nums[j] && output[i]==output[j]+1)
               {
                   dp[i]=dp[i]+dp[j];
               }
            }
            if(maxi==output[i])    // if max reached
            {
                ans+=dp[i];      // have that count
            }
        }
        return ans;

    }
};
