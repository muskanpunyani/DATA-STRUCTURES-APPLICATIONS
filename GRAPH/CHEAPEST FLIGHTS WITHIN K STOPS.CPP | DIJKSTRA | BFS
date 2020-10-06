There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

 

Constraints:

    The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
    The size of flights will be in range [0, n * (n - 1) / 2].
    The format of each flight will be (src, dst, price).
    The price of each flight will be in the range [1, 10000].
    k is in the range of [0, n - 1].
    There will not be any duplicated flights or self cycles.

****************************************************************************************************************************************************



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        // first we will create a adjacency list ; 2d vector 
        vector <vector <pair <int,int> > > v(n);   // vector of pairs will be dest n c
        for(auto i:flights)
        {
            v[i[0]].push_back({i[1],i[2]});    //src-> (dest,cost)
        }
        // create a min priority queue of pair<int,pair<int,int>>
        priority_queue < pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> >> > pq;
        
        // pushing src to pq
        pq.push({0,{src,K}});   // [cost,curr node,k]
        while(!pq.empty())  // bfs ; dijkstra
        {
            
                pair<int,pair<int,int>> p=pq.top();
                pq.pop();
                
                // check if the curr node is equal to dest
                if(p.second.first==dst)
                {
                    return p.first;   // return cost till here
                }
                if(p.second.second<0)  // if max k completed,skip the stop
                {
                    continue;
                }
                // now find adjacents and insert them to queue
                for(auto i:v[p.second.first])  // in adjacency list of curr node
                {
                    int cost_curr=p.first+i.second;  // sum the cost as curr cost and neighbour cost
                    int curr=i.first;  // the current node will be neighbour 
                    pq.push({cost_curr,{curr,p.second.second-1}}); // k i reduced to 1
                }
            }
        
        return -1;  // if no ans
        
    }
};
