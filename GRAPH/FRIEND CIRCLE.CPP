There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B,
and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

 

Example 2:

Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

 

Constraints:

    1 <= N <= 200
    M[i][i] == 1
    M[i][j] == M[j][i]

***************************************************************************************************************************************
// input is adjacent matrix
class Solution {
public:
    void dfs(int start,vector<vector<int>>& M,bool visited[100000],int n)
    {
        visited[start]=true;
        for(int i=0;i<n;i++)       // adjacent matrix
        {
            if(visited[i]!=true && M[start][i]==1)
            {
                dfs(i,M,visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        // no of connected components,no of frnd circles
        int n=M.size();
        bool visited[n+1];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        int frnds=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                frnds++;
                dfs(i,M,visited,n);
            }
        }
        return frnds;
        
    }
};
