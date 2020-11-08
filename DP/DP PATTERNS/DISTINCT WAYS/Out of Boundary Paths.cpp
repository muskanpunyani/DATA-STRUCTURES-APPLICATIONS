There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

 

Example 1:

Input: m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:

Input: m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

 

Note:

    Once you move the ball out of boundary, you cannot move it back.
    The length and height of the grid is in range [1,50].
    N is in range [0,50].

**************************************************************************************************************************************************

class Solution {
public:
    int mod=pow(10,9)+7;
    long long int answer(int m,int n,int N,int i,int j,int memo[100][100][100])
    {
        if(i==m || j==n || i<0 || j<0)  // get out of boundary
       {
         return 1;
       }
        if(N==0)
        {
            return 0; // no moves
        }
        if(memo[i][j][N]!=-1)
        {
            return memo[i][j][N]%mod;
        }
        long long int val= answer(m,n,N-1,i+1,j,memo)%mod+
            answer(m,n,N-1,i-1,j,memo)%mod+
             answer(m,n,N-1,i,j-1,memo)%mod+
            answer(m,n,N-1,i,j+1,memo)%mod;
        memo[i][j][N]=val%mod;
        return memo[i][j][N];
    }
    int findPaths(int m, int n, int N, int i, int j) {
        int memo[100][100][100];
        memset(memo,-1,sizeof(memo));
        return answer(m,n,N,i,j,memo);
    }
     
};
