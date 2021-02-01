https://leetcode.com/problems/network-delay-time/

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a 
signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

 

Note:

    N will be in the range [1, 100].
    K will be in the range [1, N].
    The length of times will be in the range [1, 6000].
    All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

******************************************************************************************************************************



bool comp(pair<int,int> v1,pair<int,int> v2 )
    {
        return v1.second<v2.second;     // sort on basis of cost
    }
class Solution {
public:
    
    int getminvertex(vector<int> &dist,vector<bool> &visited,int n)
    {
        int minvertex=-1;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i]  && (minvertex==-1 || dist[i]<dist[minvertex]))
            {
                minvertex=i;
            }
        }
        return minvertex;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int l=times.size();
        vector<vector<pair<int,int>> > m(N+1);
        for(int i=0;i<l;i++)
        {
            int a1=times[i][0];
            int a2=times[i][1];
            int a3=times[i][2];
            m[a1].push_back({a2,a3});  // adj list with weights
        }
        for(int i=0;i<m.size();i++)
        {
        sort(m[i].begin(),m[i].end(),comp); // sort on basis of cost
        }
      vector<bool> visited(N+1,false);
      vector<int> dist(N+1,INT_MAX);
        dist[K]=0;             // distance for source
        for(int i=1;i<=N;i++)
        {
            int minvertex=getminvertex(dist,visited,N);
            visited[minvertex]=true;
            for(auto j:m[minvertex]) // explore neighbours of min vertex
            {
                if(!visited[j.first])
                {
                    long long int currd=(long long int) dist[minvertex]+(j.second);
                    if(dist[j.first]>currd)
                    {
                        dist[j.first]=currd;
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=N;i++) // find max dist
        {
            if(dist[i]>ans )
            {
                ans=dist[i];
            }
        }
        if(ans==INT_MAX)   // if max is int_max,it means any of vertex cant be reached and thus soln doesnt exist
            return -1;
        return ans;
        
        
    }
};
