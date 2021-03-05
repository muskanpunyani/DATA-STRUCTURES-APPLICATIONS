

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:

    Each element in the result must be unique.
    The result can be in any order.

 

****************
class Solution {
public:
    /*
    sort the array
    take 2 pointer 1 in each array,compare both array values and then put
    dont take -ve values
    */
    // time=0(nlogn)
    // space=0(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m)
        {
            while(i!=n-1 && nums1[i]==nums1[i+1])
            {
                i++;
            }
            while(j!=m-1  && nums2[j]==nums2[j+1])
            {
                j++;
            }
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
