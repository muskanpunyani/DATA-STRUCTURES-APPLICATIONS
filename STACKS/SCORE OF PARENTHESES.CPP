Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

 

Example 1:

Input: "()"
Output: 1

Example 2:

Input: "(())"
Output: 2

Example 3:

Input: "()()"
Output: 2

Example 4:

Input: "(()(()))"
Output: 6

 

Note:

    S is a balanced parentheses string, containing only ( and ).
    2 <= S.length <= 50

******************************************************************************************************


class Solution {
public:
    int scoreOfParentheses(string S) {
        int n=S.length();
        stack<int> st;
        int score=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='(')              // evertime we see opening put 0
            {
                st.push(score);
                score=0;                  // for that pair of parentheses,score is reinitialzed
            }
           else{
               score=st.top()+max(2*score,1);     // multply twice if score is greater than 0,i.e parenthesis is child
               // 1 when score is 0,i.e parenthesis is parent so value 1 according to rule
               // addition is due to rule AB=A+B
               st.pop();   // POP THE TOP MOST ELEM AFTER UPDATING SCORE
           }
                
        }
        return score;
     
    }
};
