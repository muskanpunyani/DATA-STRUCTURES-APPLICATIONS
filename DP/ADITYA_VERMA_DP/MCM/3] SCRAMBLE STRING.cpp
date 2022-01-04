Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that “rgtae” is a scrambled string of “great”.


Given two strings A and B of the same length, determine if B is a scrambled string of S.


Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.

Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True

Constraints:

1 <= len(A), len(B) <= 50

Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
********************
map<string,int> m; //memoize
int solve(string a,string b)
{
    if(a==b)   // both strings are same then scramble
    return true;
    if(a.length()<=1)  // if both string not eq and only having 1 or less size then false
    return false;
    
    int n=a.length();
    string key=a+" "+b;
    if(m.find(key)!=m.end())
    {
        return m[key];
    }
    bool flag=false;
    for(int i=1;i<n;i++)
    {
       bool cond1= (solve(a.substr(0,i),b.substr(n-i,i))) && (solve(a.substr(i,n-i),b.substr(0,n-i))); // swap
       bool cond2=(solve(a.substr(0,i),b.substr(0,i)) && (solve(a.substr(i,n-i),b.substr(i,n-i)))); // no swap
       if(cond1 || cond2)
       {
       flag=true;
       }
    }
    m[key]=flag;
    return flag;
}
int Solution::isScramble(const string A, const string B) {

  // scramble string possibility could be
  /*
  lets say we divide string at every point as we are not aware where to swap , so mcm
  2 cases
  1] swap 
  gr|eat -->   eat|gr
  so in swap first past of string a is checked with last part of string b and vice versa
gr  -- gr
eat -- eat
  2] no swap
  great --> great  

  if 1 or 2 is true then ans is true
  */
  // base cases
  /*
  if both string are diff length, no way they can be scrambled
  if both strings are same they are already scrambled
  if both are empty cant be scrambled
  */
  if(A.empty() && B.empty())  // if both empty
  {
      return false;
  }
  if(A.length()!=B.length()) // if both having diff length
  {
      return false;
  }
  
  return solve(A,B);
}
