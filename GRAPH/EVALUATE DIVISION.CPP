You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

 

Constraints:

    1 <= equations.length <= 20
    equations[i].length == 2
    1 <= Ai.length, Bi.length <= 5
    values.length == equations.length
    0.0 < values[i] <= 20.0
    1 <= queries.length <= 20
    queries[i].length == 2
    1 <= Cj.length, Dj.length <= 5
    Ai, Bi, Cj, Dj consist of lower case English letters and digits.

******************************************************************************************************************************



class Solution {
public:
    double dfs(map<string,map<string,double>> &m,string src,string dest,set<string> & visited)
    {
        if(m.find(src)==m.end() || m.find(dest)==m.end())  // if src or dest doesnt exist in map
        {
            return -1;
        }
        if(src==dest)
        {
            return 1;
        }
        visited.insert(src);
        double ans=-1.0;
        for(auto i : m[src])
        {
           if(visited.find(i.first)==visited.end()) // not visited,i.e doesnt exist in set
           {
                 if(i.first==dest)
                 {
                   return i.second;
                 }
               double res=  dfs(m,i.first,dest,visited);
               if(res!=-1)
               {
                   return res*(i.second);
               }
            }
          }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();  // row
        map<string,map<string,double>> m;
        for(int i=0;i<n;i++)
        {
            string a1=equations[i][0];
            string a2=equations[i][1];
            m[a1].insert({a2,values[i]});
            m[a2].insert({a1,1/values[i]});
        }
        int l=queries.size();
        vector<double> res;
        for(int i=0;i<l;i++)
        {
            set<string> visited;
            string src=queries[i][0];
            string dest=queries[i][1];
            double ans=dfs(m,src,dest,visited);
            res.push_back(ans);
        }
        return res;
    }
};
