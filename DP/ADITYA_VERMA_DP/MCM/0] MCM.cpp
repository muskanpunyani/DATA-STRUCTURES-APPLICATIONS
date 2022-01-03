
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.


Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.


Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
********************************
class Solution{
    
    // time =0(n3)
    // space =0(n2)
public:
     int dp[101][101]; // dp[n+1][n+1]
    int solve(int arr[],int i,int j)
    {
        // base case, when there are 1 or less elem
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        // k range from i to j-1 bcz when k=j, solve(k+1,j) would become invalid
        for(int k=i;k<j;k++)
        {
            int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j]; // extra cost
            ans=min(ans,temp);
        }
        dp[i][j]=ans;
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // find i,j -> here i cannot be 0 as we need arr[i]*Arr[i-1] , so i will be 1
        // j will be n-1
        int i=1;
        int j=N-1;
        memset(dp,-1,sizeof(dp));
        return solve(arr,i,j);
    }
};
