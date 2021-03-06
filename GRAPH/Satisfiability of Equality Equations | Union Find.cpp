Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes 
one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

 

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.

Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Example 3:

Input: ["a==b","b==c","a==c"]
Output: true

Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false

Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true

 

Note:

    1 <= equations.length <= 500
    equations[i].length == 4
    equations[i][0] and equations[i][3] are lowercase letters
    equations[i][1] is either '=' or '!'
    equations[i][2] is '='

********************************************************************************************************************


class Solution {
public:
// using union find
// union find complexity=0(n)
    int parent[27];
       int find(int k)
    {
        if(parent[k]==k)
            return k;
        
        return find(parent[k]);
    }
    bool equationsPossible(vector<string>& equations) {
         
         for(int i=0;i<26;i++)
        {
            parent[i]=i;    // 26 characters
        }
        for(auto i:equations) // access every string of vector
        {
            if(i[1]=='=')
            {
                int x=find(i[0]-'a');
                int y=find(i[3]-'a');
                parent[x]=y;
            }
        }
        for(auto i:equations)
        {
            if(i[1]=='!')
            {
                int x=find(i[0]-'a');
                int y=find(i[3]-'a');
                if(x==y)
                    return false;
            }
        }
        return true;
    }
};
