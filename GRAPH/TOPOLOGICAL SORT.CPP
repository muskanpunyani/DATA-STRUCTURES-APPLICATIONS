You don't need to read input or print anything. Your task is to complete the function topoSort() which takes the adjacency list of the Graph and the number of vertices (N) as inputs are returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 104
1 <= E <= (N*(N-1))/2
0 <= u, v <= N-1
Graph doesn't contain multiple edges, self loops and cycles.
Graph may be disconnected.

Example:
Input
2
6 6
5 0 5 2 2 3 4 0 4 1 1 3
3 4
3 0 1 0 2 0

Output:
1
1

Explanation:
Testcase 1: The output 1 denotes that the order is valid.  So, if you have implemented your function correctly, then output would be 1 for all test cases.
// The Graph structure is as folows
*****************************************************************************************************************************************************
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void dfs(int source,vector<int> adj[],vector<int> &ans,bool *visited)
{
    for(auto it:adj[source])
    {
        if(visited[it]==false)
        {
     dfs(it,adj,ans,visited);
        }
    }
    if(visited[source]==false)
    {
    ans.push_back(source);  // push source when it is having no neighbors
    // rest is normal dfs
    visited[source]=true;
    }
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector<int> ans;
    bool* visited=new bool[V+1];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            dfs(i,adj,ans,visited);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
