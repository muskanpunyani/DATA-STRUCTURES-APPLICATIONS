You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. 
In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. 
The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

 

Constraints:

    1 <= n <= 104
    0 <= paths.length <= 2 * 104
    paths[i].length == 2
    1 <= xi, yi <= n
    xi != yi
    Every garden has at most 3 paths coming into or leaving it.

************************************************************************************************************************************


class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int l=paths.size();
        vector<vector<int>> graph(n+1);
        vector<int> result(n,-1);
        vector<int> ans(n,1);
        if(l==0)
        {
            return ans;
        }
           
        for(int i=0;i<paths.size();i++)  // bidirectional
        {
            int u=paths[i][0];
            int v=paths[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
       
        for(int i=1;i<=n;i++)
        {
            vector<int> colour(5,0); // each color is available
          
            for(int j:graph[i]) // visit adjacent of ith node
            {
              if(result[j-1]!=-1)
              colour[result[j-1]]=1;  // color[result] bcz color lies bn 1 and 4 only
    // marking color for those result values so that coloring is not repaeated
            }
            for(int k=1;k<=4;k++)
            {
                // the one which are not colored are colored here
                if(colour[k]==0)    // i.e still not used
                {
                    result[i-1]=k;
                    break;
                }
            }
            
        }
        return result;
        
        
    
    }
};
