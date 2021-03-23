There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:



Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
 

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.

*******************************
class Solution {
public:
    /*
    (Number of connected components-1 ) is the requied answer.
Just think none of the computers are connected.Clearly n-1 is the minimum number of wires required to connect them.
Now visualise each of those computers as connected components.As once we reach one of the computers in the connected component we reach everything in that component.So, (Number of connected components-1 ) is the requied answer.

Now twist is that to connect all computers you need n-1 wires.But so if total wires less than n-1 return -1.


if the size of given 2d array,i.e the number of edges is less tha n-1,it will  not be possible to have a connected network
if it is more or equal to n-1, we can have connected network and connected_components-1 is ans
as we are having sufficient edges to connect whole graph
    */
    // time=0(n)
    // space=0(n)
    void dfs(int start,vector<bool> &visited,vector<vector<int>>& graph)
    {
        visited[start]=true;
        for(auto it:graph[start])
        {
            if(!visited[it])
            {
                dfs(it,visited,graph);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            graph[u].push_back(v);  // bidirectional  graph
            graph[v].push_back(u);
        }
        int components=0;  // no of connected components
        vector<bool> visited(n,false);
       for(int i=0;i<n;i++)
       {
           if(visited[i]==false)
           {
               components++;
               dfs(i,visited,graph);
               
           }
       }
       if(connections.size()>=(n-1))// condition of edges (min edges)
       {
           return components-1;   
       } 
        return -1;   // condition not satisfied
        
        
    }
};
