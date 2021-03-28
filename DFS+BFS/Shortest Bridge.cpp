In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: A = [[0,1],[1,0]]
Output: 1

Example 2:

Input: A = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

 

Constraints:

    2 <= A.length == A[0].length <= 100
    A[i][j] == 0 or A[i][j] == 1



*****************************
class Solution {
public:
    /*
    1] find the first island through dfs,store its coordinates
    2] now bfs from 1st island coordinates until you find 2nd island ,i.e a unvisited 1
    */
    // time=space=0(nm)
    int n,m;
    int x[4]={0,1,0,-1}; // dirns
    int y[4]={1,0,-1,0};
    bool isvalid(int r,int c)
    {
        if(r>=0 && r<n && c>=0 && c<m)
        {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<bool>> &visited,vector<vector<int>>& A,int r,int c)
    {
        if(!isvalid(r,c) || A[r][c]!=1 || visited[r][c]==true)
        {
            return;
        }
        visited[r][c]=true;
        dfs(visited,A,r+1,c);
        dfs(visited,A,r-1,c);
        dfs(visited,A,r,c+1);
        dfs(visited,A,r,c-1);
    }
    int shortestBridge(vector<vector<int>>& A) {
        n=A.size();
        m=A[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        bool found=false;
        for(int i=0;i<n;i++)
        {
            if(found)   // need to dfs for only 1 island
                break;
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && A[i][j]==1) // if isalnd and not visited
                {
                    dfs(visited,A,i,j);
                    found=true;
                    break;
                }
            }
        }
        
        // bfs
        // visited 1's of 1st island,i.e every cordinate of first island is inserted into queue and we will find next island 
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==true) 
                {
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int x1=p.first;
                int y1=p.second; // x1 and y1 are already visited then inserted in queue
                for(int k=0;k<4;k++) // 4 dirn
                {
                    int x2=x1+x[k];
                    int y2=y1+y[k];
                    if(isvalid(x2,y2) && visited[x2][y2]==false)
                    {
                        if(A[x2][y2]==1) // if adj 1
                        {
                            return ans;
                        }
                        // else
                        q.push({x2,y2}); // push 0s
                        visited[x2][y2]=true; // make it visited
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
