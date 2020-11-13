There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

 

Constraints:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5

********************************************************************************************************************************


class Solution {
public:
   
    bool dfs(vector<bool> &visited,vector<bool> &helper,int start,vector<vector<int>> &graph)
    {
        if(helper[start]==true)
            return true;
        visited[start]=true;
        helper[start]=true;
        
        for(auto i:graph[start])
        {
            if(helper[i]==true)
                return true;
            if(visited[i]==false)
            {
                bool ans=dfs(visited,helper,i,graph);
                if(ans==true)
                    return true;
            }
        }
        helper[start]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // PREREQUISITES is graph in form of adj list
        // need to find if graph is containing cycle,if yes then return false
        vector<bool> visited(numCourses,false);
        vector<bool> helper(numCourses,false);
        int n=prerequisites.size();
        if(n==0)                        // no elements,i.e no courses
        {
            return true;
        }
        vector<vector<int>> graph(numCourses);  // if size not given runtime error
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[v].push_back(u);           // u is start in required
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                bool ans=dfs(visited,helper,i,graph);
                if (ans==true)                           // true means cycle
                {
                    return false;              // return false as course scheduling will not be possible if cycle exist
                }
            }
        }
        return true;

        
    }
};
