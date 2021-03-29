A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

Example 2:

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]

Example 3:

Input: n = 1, edges = []
Output: [0]

Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]

 

Constraints:

    1 <= n <= 2 * 104
    edges.length == n - 1
    0 <= ai, bi < n
    ai != bi
    All the pairs (ai, bi) are distinct.
    The given input is guaranteed to be a tree and there will be no repeated edges.



********************************
class Solution {
public:
    /*
    Once we trim out the first layer of the leaf nodes (nodes that have only one connection), some of the non-leaf nodes would become leaf nodes.

The trimming process continues until there are only two nodes left in the graph, which are the centroids that we are looking for.
    

    1]Initially, we would build a graph with the adjacency list from the input.

    2]We then create a queue which would be used to hold the leaf nodes.

    3]At the beginning, we put all the current leaf nodes into the queue.

    4]We then run a loop until there is only two nodes left in the graph.

    5]At each iteration, we remove the current leaf nodes from the queue. While removing the nodes, we also remove the edges that are linked to the nodes. As a consequence, some of the non-leaf nodes would become leaf nodes. And these are the nodes that would be trimmed out in the next iteration.

    6]The iteration terminates when there are no more than two nodes left in the graph, which are the desired centroids nodes.

    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // time=0(n)
       // leaf nodes will have only 1 edge which will be its parent
        if(n==1) // only 1 edge,base case
        {
            return {0};
        }
        vector<unordered_set<int>> graph(n);  //creating graph as vector of unordered set so the adj list will be dtored in set and it will be easirer to remove leaf nodes
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        // now we will insert leaf nodes in queue
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].size()==1) // if i is leaf,only 1 adj
            {
                q.push(i);
            }
        }
        while(n>2)
        {
            int len=q.size();
            n=n-len;
            for(int i=0;i<len;i++)
            {
                int leaf=q.front();
                q.pop();
                for(auto it:graph[leaf])
                {
                    graph[it].erase(leaf); // remove its linking,i.e remove this adjacent leaf from adjacency list
                    if(graph[it].size()==1)
                        q.push(it);
                }
            }
            
        }
        // now q will contain centroids
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
