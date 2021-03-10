Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

 

Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length



*************************
class Solution {
public:
    // sliding window
    /*
    exactly k=atmost k-atmost (k-1)
    here we want exactly k odd,we can find atmost k number of arrays using sliding window
    lets say k=3
    atmost(k)= 0 odd,1 odd,2 odd,3 odd
    atmost(k-1)=0 odd,1 odd,2 odd
    subtracting both => rem=3 odd (i.e exact 3)
    i.e we got exact k
    
    now subarrays having atmost k is easy through sliding window,just resuce window from left if greater than k odd and for everything else add (end-start+1) to ans,as this all no of arrays will be possible
    */
    // time=0(n); space=0(1)
    int answer(vector<int>& nums,int k)
    {
         int n=nums.size();
        int start=0;
        int end=0;
        int odd=0;
        int ans=0;
        for(end=0;end<n;end++)
        {
            int temp=nums[end];
            if((temp%2)!=0)
            {
                odd++;
            }
            while(odd>k)
            {
               
                int temp2=nums[start];
                if((temp2%2)!=0)
                {
                    odd--;
                }
                start++;
               
            }
            ans+=(end-start+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       
       return answer(nums,k)-answer(nums,k-1);
    }
};
