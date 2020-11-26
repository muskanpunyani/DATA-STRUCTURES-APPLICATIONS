Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

 

Constraints:

    1 <= s.length <= 104
    s consists of lowercase English letters.

*************************************************************************************************
// find freq of every char
// put char in stack if stack is empty 
// if the top of stack is greater than current char and it will occur again then remove it and make it false

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> m;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        bool visited[100]={false}; // a=0,b=1,c=2.....etc
        
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
           if(visited[s[i]-'a']==true)        // if char occurred already 
            {
                m[s[i]]--;
                continue;
            }
         
        while((st.empty()==false) && st.top()>s[i] && m[st.top()]>0)   // if char is less than top char and it will occur in future,then remove top
            {
                visited[st.top()-'a']=false;
                st.pop();
              
            }
           st.push(s[i]);
           m[s[i]]--;
          visited[s[i]-'a']=true;
         }
        string ans;
        while(st.empty()==false)
        {
            ans=st.top()+ans;       // reversed in stack
            st.pop();
        }
        return ans;
    }
};
