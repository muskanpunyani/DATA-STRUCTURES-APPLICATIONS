Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.

 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200 
***********************
class Solution{
public:
unordered_map<string,long long int> m;
    int solve(string s,int i,int j,bool istrue)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j) // only 1 character, so if that char is t then t else f
        {
            if(istrue)// if true and chr is truue then true else false
              return s[i]=='T';
            else  // if we need false and char is also false return 1 else 0
              return s[i]=='F';
        }
        string key=to_string(i)+" "+to_string(j)+" "+ to_string(istrue);
        if(m.find(key)!=m.end())  // presnt in map?
        {
            return m[key];
        }
        
        // k from i+1 to j-1  // operator
        long long int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            long long int lefttrue=solve(s,i,k-1,true);
            long long int leftfalse=solve(s,i,k-1,false);
            long long int righttrue=solve(s,k+1,j,true);
            long long int rightfalse=solve(s,k+1,j,false);
            if(s[k]=='&')
            {
                if(istrue)
                ans=ans+(lefttrue*righttrue);
                else
                ans=ans+(lefttrue*rightfalse)+(leftfalse*righttrue)+(leftfalse*rightfalse);
            }
            else if(s[k]=='|')
            {
                if(istrue)
                ans=ans+(lefttrue*rightfalse)+(leftfalse*righttrue)+(righttrue*lefttrue);
                else
                ans=ans+(leftfalse*rightfalse);
            }
            else if(s[k]=='^')
            {
                if(istrue)
                ans=ans+(lefttrue*rightfalse)+(leftfalse*righttrue);
                else
                ans=ans+(lefttrue*righttrue)+(leftfalse*rightfalse);
            }
        }
        m[key]=ans%1003;  // given in description 
        return ans%1003;
    }
    int countWays(int N, string S){
        // k will be operators, so k+2
        // find i,j first i=0, j=n-1
        
        int i=0;
        int j=N-1;
        bool istrue=true;  // bcz req is true vaulue
        return solve(S,i,j,istrue);
    }
};
