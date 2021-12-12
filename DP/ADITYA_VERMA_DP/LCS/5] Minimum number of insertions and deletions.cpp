Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.

Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 insertions

 

Your Task:
You don't need to read or print anything. Your task is to complete the function minOperations() which takes both strings as input parameter and returns the minimum number of operation required.

Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lower case English alphabets


***********************
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    /*
	    heap pea
	    pheap - added p
	    pea - deleted h and p
	    
	    unchanged part = ea
	    what is ea - lcs of both strings
	    lcs= length 2
	    
	    if we notice carefully = deletion === str1.length -lcs
	    insertion== str2.length - lcs
	    
	    // we need to return insertion + deletion
	    */
	    int n= str1.length();
	    int m= str2.length();
	    
	    // find lcs first
	    int dp[n+1][m+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    int lcs=dp[n][m];
	    int deletion = n -lcs;
	    int insertion = m-lcs;
	    int ans= deletion + insertion;
	    
	    return ans;
	    
	} 
};
