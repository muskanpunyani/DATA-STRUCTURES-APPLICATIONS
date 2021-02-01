In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  
If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.
More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  
The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

    graph will have length at most 10000.
    The number of edges in the graph will not exceed 32000.
    Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].

*************************************************************************************************************************************

// if we reach terminal node from any node,i.e not end up in cycle then that is safe
class Solution {
public:
    bool dfs(vector<int> &color,vector<vector<int>>& graph,int start)
    {
        if(color[start]>0)        
        {
            if(color[start]==1)   // if 1 means cycle
                return false;
            else
                return true;      // if 2 means terminal , return true
        }
        color[start]=1;           // initially mark 1
        for(auto i:graph[start])   // check adjacent
        {
            if(color[i]==2) // reached terminal
                continue;
            if(color[i]==1 || dfs(color,graph,i)==false)  // if results in loop
                return false;
        }
        color[start]=2; // if above for condition fails,i.e no loop ; mark this node as terminal 
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // initially color=0, 1 means=cycle,2 means terminal
        vector<int> color(n+1,0);
        vector<int> ans;
        for(int i=0;i<n;i++)    // check for every node,cycle or not
        {
            if(dfs(color,graph,i))
            {
                ans.push_back(i);  // if no cycle for that node
            }
        }
        return ans;
        
    }
};
