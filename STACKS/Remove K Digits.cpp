Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
***************************************************************************************************************************************

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k)        // if same then every char will be deleted
        {
            return "0";
        }
        stack<char> s;
        s.push(num[0]);              // push 1st numn=ber
        for(int i=1;i<num.length();i++)
        {
            while(k>0 && s.empty()==false && s.top()>num[i]) // we got a decline,pop the decline point
            {
               s.pop();
                k--;
            }
            s.push(num[i]);   // else push everything
        }
       
        for(int i=0;i<k;i++)
        {
            if(s.empty()==false)     // pop rem k,last elements
            s.pop();
        }
        
       
        string ans="";
       while(s.empty()==false)
        {
            ans=s.top()+ans;
            s.pop();
        }
    
        ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1)); // remove leading 0s from string
        return ans;
    }
};
