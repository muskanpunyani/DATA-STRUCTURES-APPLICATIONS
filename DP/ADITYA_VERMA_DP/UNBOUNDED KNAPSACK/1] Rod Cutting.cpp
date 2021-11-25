Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24. 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 105
*****************
class Solution{
  public:
    int cutRod(int price[], int N) {
        //length array is not given but it will have 1 to n as no other condition is stated
        int length[N+1];
        for(int i=0;i<N;i++)
        {
          length[i]=i+1;
        }
        
        // this prob is same as knapsack
        // length= wt arr
        // price = val arr
        // N =W
        
        int dp[N+1][N+1]; //total is N and length of arr is also N
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(length[i-1]<=j)
                {
                    dp[i][j]=max(dp[i-1][j], price[i-1]+dp[i][j-length[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[N][N];
    }
};
