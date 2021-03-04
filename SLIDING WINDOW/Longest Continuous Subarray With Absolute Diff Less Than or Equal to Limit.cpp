Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

 

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    0 <= limit <= 10^9




class Solution {
public:
    /*
    maximum element-minimum elemnt <=limit
    brute force way is to tke very subarray and find diff bn min and max
    1] correct way would be to create a map,take diff bn end and start and update the length if it exceeds the limit,as start and end of map will contain min and max elemnt
    */
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=0;
        map<int,int> m;
        int windowstart=0;
        int start,end;
        for(int i=0;i<n;i++)
        {
            int left=nums[i];
            m[left]++;
            int mini=m.begin()->first;
            int maxi=m.rbegin()->first;
            if((maxi-mini)>limit)
            {
                int right=nums[windowstart];
                m[right]--;
                if(m[right]<=0)  // if that number end
                {
                    m.erase(right);
                }
                windowstart++;
            }
            ans=max(ans,i-windowstart+1); // update length
        }
        return ans;
    }
};
