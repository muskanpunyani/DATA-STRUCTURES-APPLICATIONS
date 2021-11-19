Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.


Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
********************
class Solution{
public:
int subsetsum(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 && j>0)
            {
                dp[i][j]=false;
            }
            else if(j==0)
            {
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]==true)
    return 1;
    else
    return 0;
}
    int equalPartition(int N, int arr[])
    {
        // partition can be possible if arr total sum is even
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum=sum+arr[i];
        }
        if((sum%2)!=0) // odd sum not possible
        {
            return 0;
        }
        // else even sum
        return subsetsum(arr,N,sum/2);  // call subset sum question function and check if sum/2 is possible over there
    }
};
