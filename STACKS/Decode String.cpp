Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
************************************************************************************************************************


class Solution {
public:
  
    string decodeString(string s) {
         int n=s.length();
         stack<string> st;
         string ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')     // if closing brace
            {
            string val;
           while(st.empty()==false && s[i]==']' && st.top()!="[")
           {
               val=st.top()+val;                      // find string
               st.pop();
           }
           st.pop();  // pop the '['
           
          string number="";
          while(!st.empty() && (st.top()>="0" && st.top()<="9")){  // find the no of time string val is repeated
                    number = st.top() + number;
                    st.pop();
                }
            int k=stoi(number);  // convert string to int
           ans="";
           for(int j=0;j<k;j++)
           {
               ans=ans+val;             // find ans
           }
           st.push(ans);             // push 
            }
            else{
                st.push(string (1,s[i])); // for everything else,push directly on stack
                // convert char to string
            }
            
        }
        
       string res;
        while(st.empty()==false)    //stack consist result
        {
            res=st.top()+res;       // reversed order
            st.pop();              
        }
       return res; 
    }
};
