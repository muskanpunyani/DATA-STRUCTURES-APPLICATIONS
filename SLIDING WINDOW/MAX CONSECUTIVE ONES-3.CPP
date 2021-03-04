Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

 

Note:

    1 <= A.length <= 20000
    0 <= K <= A.length
    A[i] is 0 or 1 




class Solution {
public:
    /*
    we can change upto k values
    we will traverse the array and keep a count of 1,if 1 is max we will convert all zeros
    if the os are greater than k,we will reduce the window size from beg
    */
    // time=0(n)
    // space=0(1)
    int longestOnes(vector<int>& A, int K) {
        int onecount=0;
        int start=0;
        int end=0;
        int n=A.size();
        int ans=INT_MIN;
        for(end=0;end<n;end++)
        {
            if(A[end]==1)
            {
                onecount++;
            }
            if(end-start+1 -onecount >K)
            {
                if(A[start]==1)
                {
                    onecount--;
                }
                start++;
            }
            ans=max(end-start+1,ans);
        }
        return ans;
    }
};
