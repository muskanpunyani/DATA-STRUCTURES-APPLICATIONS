Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

****************************************************************************************************************


class Solution {
public:
    bool isValid(string s) {
        // PUT EVERY OPENING BRACKET ON THE STACK
        // FOR CLOSING BRACKET, CHECK IF THE BRACKET AND THE TOP OF THE STACK ARE EQUAL, IF YES POP 
        // ELSE RETURN FALSE
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') //. opening
            {
                st.push(s[i]);
            }
            else if((s[i]==')'|| s[i]=='}' || s[i]==']' )&& st.empty()==false)  // stack should not be empty at the time of closing bracket
            {
                if((s[i]==')' && st.top()=='(')  || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')  )
                {
                    st.pop();
                }
                else{                     // if stack is empty,when close bracket arise or any other invalid case
                    return false;
                }
            }
             else 
             {
                 return false;
             }
            
        }
        if(st.empty())  // if nothing remains in stack,i./e string is balanced
        {
        return true;
        }
        return false;
    }
};
