You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"

Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

 

Constraints:

    1 <= s.length <= 2000
    s only contains lower case English characters and parentheses.
    It is guaranteed that all parentheses are balanced.


***********************************
class Solution {
public:
    /*
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                string temp;
                while(!st.empty() && st.top()!="(")
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                st.push(temp);
            }
            else{
               st.push(string(1,s[i]));
            }
        }
        string ans;
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

/*

Explanation =>
1] Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

(ed (et (oc)) el)
          |
(ed(  et co ) el)
        |
(ed  octe   el)
        |
(leetcode)

so first oc is reversed most inner bracket
then et + reverse(oc)  = et + co => reversed => octe
till we reach end

so what we are doing is
1. push char in stack if its not closing bracket
2. if we receive closing bracket pop everythoing bn ( ) and create a temp string reverse that string and push back to stack
3. in the end the elem in stack would be ans
4. all rem elem instead of just stack top due to below testcase where not everything is under paranthesis.


Input
"a(bcdefghijkl(mno)p)q"
Output
"q"
Expected
"apmnolkjihgfedcbq"


this soln is 0(n2) , o(n) for traversing string and inner o(n) for reversal
*/


// solution 2 - lee's solution
/*
time =0(n)
1. strore the index of parenthesis in reverse fashion
i.e for '(' - store index of ')' and viceversa
2. everything is reversed inside bracket so let's say we arrive at '(' then move till ')' and add the char to output, it will automatically be added in reverse fashion

eg. l e e ( c t ) o d e
    0 1 2 3 4 5 6 7 8 9
    
    when we reach at index 3, '(' jump to index 6 and move in reverse order
    ans = lee + t + c 
    again got '(', jump to 6 and continue in +ve direction
    ans = lee + t+ c + ode
    
    i.e whenever brac, change direction
    
    we will use d for direction.
*/
     string reverseParentheses(string s) {
         int n=s.length();
         vector<int> pair(n);
         vector<int> opened_brackets;
         for(int i=0;i<s.length();i++)
         {
             if(s[i]=='(')
             {
                 opened_brackets.push_back(i);
             }
             else if(s[i]==')')
             {
                 int open=opened_brackets.back();
                 opened_brackets.pop_back();
                 // closing parenthesis index is i
                 pair[i]=open;    // closing point has open val
                 pair[open]=i;    // opened index has closed value
             }
         }
         int d=1;
         string ans;
         for(int i=0;i<s.length();i+=d)
         {
             if(s[i]=='(' || s[i]==')')
             {
                 i=pair[i];
                 d=-d;
             }
             else{
                 ans+=s[i];
             }
         }
         return ans;
     }
};
