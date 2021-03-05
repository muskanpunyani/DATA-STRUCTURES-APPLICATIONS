Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?



*********************
class Solution {
public:/*
array is sorted but the problem can arise due to negative number
we will take 2 pointers one at front and other at end
take square of both numbers at both the pointers and the one with max value is kept at last
// filling element from last
time=0(n)
space=0(n)
*/
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0;
        int j=nums.size()-1;
        int k=n-1;
        while(i<=j && k>=0)
        {
            int v1=nums[i]*nums[i];
            int v2=nums[j]*nums[j];
            if(v1>v2)
            {
                ans[k]=v1;
                i++;
                k--;
            }
            else{
                ans[k]=v2;
                j--;
                k--;
            }
        }
        return ans;
    }
};
