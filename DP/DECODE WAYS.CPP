A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.

Example 4:

Input: s = "1"
Output: 1

 

Constraints:

    1 <= s.length <= 100
    s contains only digits and may contain leading zero(s).

*****************************************************************************************************************************

class Solution {
public:
    bool containszero(string s)   // if the input string contains all 0
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='0')
            {
                return false;
            }
        }
        return true;
    }
    int numDecodings(string s) {
        int l=s.length();
        if(l==0 )
        {
            return 0;
        }
        if(containszero(s))
        {
            return 0;
        }
        if(s[0]=='0')
        {
            return 0;
        }
        int *output=new int[l+1];
        output[0]=1;
        output[1]=1;  // length 1,then only 1 way possible
        for(int i=2;i<=l;i++)
        {
            output[i]=0;
            if(s[i-1]>'0')  // if input is greater than 0 (i-1,bcz 0 based indexing)
            {
            output[i]=output[i-1];
            }
            
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))  // less than 26
            {
                output[i]+=output[i-2];
            }
        }
        int ans= output[l];
        return ans;

        
    }
};
