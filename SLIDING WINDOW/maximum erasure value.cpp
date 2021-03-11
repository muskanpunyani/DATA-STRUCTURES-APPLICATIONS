You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 104



******************
class Solution {
public:
    // sliding window
    // time=0(n)
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int start=0;
        int sum=0;
        unordered_set<int> s;
        int maxsum=0;
       for(int i=0;i<nums.size();i++)
       {
           while(s.find(nums[i])!=s.end()) // if already present so many nums[i],then reduce window from left
               // jab tak vo elemnt set se ni hat ta,i..e repeating wala ,elemnts start se remove krte jao and window small krte jao
           {
               int val=nums[start];
               s.erase(val);
               start++;
               sum=sum-val;
            }
           s.insert(nums[i]); // now we can safely insert this elem as it will be unique
           sum=sum+nums[i];
           maxsum=max(sum,maxsum);
           
           
           
       }
        return maxsum;
    }
};
