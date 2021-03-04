You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 

Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.

Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.

 

Constraints:

    1 <= s.length, t.length <= 10^5
    0 <= maxCost <= 10^6
    s and t only contain lower case English letters.

Accepted
20,181
Submissions
45,880

class Solution {
public:
    /*
    take every possible substring and check the cost and length,this will be brute force way
    another way is sliding window,traverse te array and the moment at which the cost exceeds max cost decrease the window from left and change the cost accordingly,update the maxlen
    */
    int equalSubstring(string s, string t, int maxcost){
        int n=s.size();
        int maxlen=0;
        int cost=0;
        int windowstart=0;
        for(int i=0;i<n;i++)
        {
           
            if(s[i]!=t[i]){  // if chr not same
                int val=abs(s[i]-t[i]);
                cost+=val;
            }
            if(cost>maxcost)
            {
                if(s[windowstart]!=t[windowstart])
                {
                    cost=cost-(abs(s[windowstart]-t[windowstart]));
                }
                windowstart++;
            }
            maxlen=max(maxlen,i-windowstart+1);
        }
        return maxlen;
    }
};
