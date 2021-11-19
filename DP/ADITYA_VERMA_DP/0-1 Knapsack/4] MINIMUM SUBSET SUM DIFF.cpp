Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:

Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4


Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106
*****************
class Solution{

  public:
  vector<int> subsetsum(int arr[],int n,int sum)
  {
      bool dp[n+1][sum+1];
      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=sum;j++)
          {
              if(i==0 && j>0)
              dp[i][j]=false;
              else if(j==0)
              dp[i][j]=true;
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
      vector<int> v1;
      for(int j=0;j<=sum;j++)
      {
          if(dp[n][j]==true)
          {
              v1.push_back(j);
          }
      }
      return v1;
  }
	int minDifference(int arr[], int n)  { 
	    // s1-s2  =min
	    // s2=total-s1 ; total-2s1=min
	    // finding s1 in range using subset sum
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    // range=(0,sum)
	    vector<int> v=subsetsum(arr,n,sum);
	    int ans=INT_MAX;
	    for(int i=0;i<=(v.size()/2);i++)
	    {
	        ans=min(ans,abs(sum-(2*v[i])));
	    }
	    return ans;
	} 
};
