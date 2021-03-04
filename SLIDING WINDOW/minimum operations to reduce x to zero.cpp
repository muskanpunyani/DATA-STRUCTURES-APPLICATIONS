You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 104
    1 <= x <= 109

Accepted
29,467
Submissions
88,301



class Solution {
public:
    /*
    we are taking every prefix sum and finding x-prefix sum in suffix sum map and taking smallest val possible
    */
    // time=0(n)
    // space=0(n)
    // explanation in book
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
         int ans=INT_MAX;
        int prefix=0;
        map<int,int> m;  // suffix sum and length
        int sum=0; // arr sum
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(x > sum) // base case
        {
            return -1;
        }
        // fill suffix map
        int suffix=0;
        for(int i=n-1;i>=0;i--)
        {
            suffix=suffix+nums[i];
            m[suffix]=n-i;    // length
            if(suffix==x)   // if we got x from suffix
            {
                ans=min(ans,m[suffix]);
            }
        }
       
        for(int i=0;i<n;i++)
        {
            prefix=prefix+nums[i];
            if(prefix==x)    // if we got x from prefix
            {
                ans=min(ans,i+1);
            }
            int temp=x-prefix;
            if(m.find(temp)!=m.end())  // finding x-prefix in suffix
            {
                ans=min(m[temp]+i+1,ans);
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
