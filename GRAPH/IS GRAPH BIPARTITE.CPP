Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

 

Note:

    graph will have length in range [1, 100].
    graph[i] will contain integers in range [0, graph.length - 1].
    graph[i] will not contain i or duplicate values.
    The graph is undirected: if any element j is in graph[i], then i will be in graph[j].

*****************************************************************************************************************************************

// 2 colour should be given to graph such that adjacent are having different colours
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // -1=uncolored
        //1= color 1
        // 0= color 2
        int v=graph.size();   // no of vertice
        int *visited=new int[v+1];
        for(int i=0;i<v;i++)
        {
            visited[i]=-1;   // means uncolored
        }
        // bfs
       queue<int> q;
        for(int i=0;i<v;i++) // for loop bcz,if the chosen vertex is not having adjacecy list; the queue will be empty
        {
            if(visited[i]==-1)
            {
              q.push(i);
              visited[i]=1;   // give initial color
            }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it:graph[temp])
            {
                if(visited[it]==visited[temp])
                {
                    return false;        // i.e the dj node and curr node is having same color
                 }
                if(it==temp)
                {
                    return false;   // self edge
                }
                if(visited[it]==-1) // not visited
                {
                visited[it]=1-visited[temp];  // if temp is color 1,it is 0;if 0,it is 1
                q.push(it);
                }
            }
        }
        }
        return true;
    }
};
