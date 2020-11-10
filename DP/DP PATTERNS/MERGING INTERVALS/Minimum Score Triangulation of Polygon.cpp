Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

Example 1:

Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:

Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.

Example 3:

Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

 

Note:

    3 <= A.length <= 50
    1 <= A[i] <= 100

********************************************************************************************************************************


class Solution {
public:
    int answer(vector<int> &A,int i,int j,int dp[100][100])
    {
        int n=A.size();
        if(i<0 || j>=n)
        {
            return 0;
        }
        if(i+1==j)  // 2 vertices only left
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
         int res=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int left=answer(A,i,k,dp);
             int right=answer(A,k,j,dp);
           long long int val=(long long int)left + (A[i]*A[j]*A[k]) + (long long int)right;
           if(val < res)
           {
               res=val;
           }
        }
        dp[i][j]=res;
        return res;
    }
    int minScoreTriangulation(vector<int>& A) {
       int n=A.size();
        // i,j,k
        // i=start=0
        // j=end=n
        int dp[100][100];
        memset(dp,-1,sizeof(dp));
        return answer(A,0,n-1,dp);
        
    }
};
