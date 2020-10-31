You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.

 

Constraints:

    1 <= strs.length <= 600
    1 <= strs[i].length <= 100
    strs[i] consists only of digits '0' and '1'.
    1 <= m, n <= 100

********************************************************************************************************





class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size(); // no of strings in vector
        vector<pair<int,int>> v(size);  // vector to store count of 0s and 1s of every string
        for(int i=0;i<size;i++)
        {
            int one=count(strs[i].begin(),strs[i].end(),'1');
            int zero=strs[i].size()-one;
            v[i]={zero,one}; // no of zero and no of one
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // dp
        for(int k=0;k<size;k++) // taking every string
        {
            int one_count=v[k].second;
            int zero_count=v[k].first;
            for(int i=m;i>=zero_count;i--)
            {
                for(int j=n;j>=one_count;j--)
                {
                   if(i==0 && j==0) // this condition doesnt make any diff
                    {
                       // ignore <0,0>
                        continue;
                    }
                    
                    dp[i][j]=max(dp[i][j],dp[i-zero_count][j-one_count]+1);
                }
            }
        }
        int ans=dp[m][n];
        return ans;
    }
};
