Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]

Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]

Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]

 

Constraints:

    n == graph.length
    2 <= n <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i (i.e., there will be no self-loops).
    The input graph is guaranteed to be a DAG.



class Solution {
public:
    void dfs(int src,vector<vector<int>> &res,vector<int> ans,vector<vector<int>>& graph,int n)
    {
        if(src==n)
        {
         //  ans.push_back(src);  // it will lead to repeated adding
            res.push_back(ans);
        }
        for(auto i : graph[src])  // 0->1,2
        {
            ans.push_back(i);      // 1; now it will insert next child in continuity
            // 1,2;                     // but we want only 1 child of 0 each time
            dfs(i,res,ans,graph,n); // dfs for 1 // dfs for 2
            ans.pop_back();      // therefore popping back one child after its traversal is over
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // Tthe graph is itself an adjacency list for i
        // for every i,graph[i] is the list
        vector<vector<int>> res;
        vector<int> ans;
        ans.push_back(0);  // 1st node
        int n=graph.size()-1;  // end node n-1
        dfs(0,res,ans,graph,n);
        return res;
    }
};
