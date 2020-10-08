Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
    One must use all the tickets once and only once.

Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

*********************************************************************************************************************************
class Solution {
public:
    void dfs(string source,map<string,priority_queue<string,vector<string>,greater<string>> > &m,vector<string> &ans)
    {
        auto &it=m[source];
        while(!it.empty())
        {
        //priority_queue<string,vector<string>,greater<string> > pq=m[source];
        string str=it.top();
        it.pop();
        dfs(str,m,ans);
        }
        
        ans.push_back(source); // if no neighbours push
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map <string,priority_queue<string,vector<string>,greater<string> > > m;
        for(int i=0;i<tickets.size();i++) // rows traversing
        {
            string s=tickets[i][0];    // source
            string v=tickets[i][1];   // destination
            m[s].push(v);                  // making priority queue for particular string
        }
        vector<string> ans;
        dfs("JFK",m,ans);  // passing source and map(i.e adj list)
       reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
