Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 

Constraints:

    1 <= n <= 19

****************************************************************************************************************************************

class Solution {
public:
    int result(int n,int* output)
    {
        int ans=0;
         if(n==0)
      {
          return 1;
      }
      if(n==1)
      {
          return 1;
      }
      for(int k=1;k<=n;k++)
      {
          if(output[k-1]==-1)                     //  
          {
              output[k-1]=result(k-1,output);
          }
          if(output[n-k]==-1)                     // 
          {
              output[n-k]=result(n-k,output);
          }
           ans+=output[k-1]*output[n-k];
      }
        
        return ans;
    }
    int numTrees(int n) {
     
     int* output=new int[n+1];
     for(int i=0;i<=n;i++)
     {
         output[i]=-1;
     }
        return result(n,output);
             
        
    }
};
