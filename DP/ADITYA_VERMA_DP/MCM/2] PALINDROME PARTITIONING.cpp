Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".


Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500
*******************************
class Solution{
public:
int dp[501][501];
bool ispalindrome(string s,int i,int j)  // i,j are first and last index
{
    if(i>j)
    return false;
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
    int solve(string str,int i,int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)  // 1 char
        {
            return 0;
        }
        if(ispalindrome(str,i,j)) // if normal string pass krege to har bar ye puri string palindrome hai ya ni check krega bcz string to change ni ho ri
        // thats why we will also pass i,j so that us particular range ki string ko check krega ye
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
        return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int left,right,temp; // for more optimization left right
            // basically 1+ 2 function calls.
            // them ans is min of temp ans
            if(dp[i][k]!=-1)
            {
                left=dp[i][k];
            }
            else{
                dp[i][k]=solve(str,i,k);
            }
            left=dp[i][k];
            if(dp[k+1][j]!=-1)
            {
                right=dp[k+1][j];
            }
            else{
                dp[k+1][j]=solve(str,k+1,j);
            }
            right=dp[k+1][j];
            
            temp= left + right +1 ;
            ans=min(ans,temp);
        }
        dp[i][j]=ans;
        return ans;
    }
    int palindromicPartition(string str)
    {
        // max cut = n-1
        // if string is palindrome 0 partition
        // if string is having only 1 character, then its palindrome
        // we dont know palindrome can be at every point so check every k so MCM
        // i,j = i=0 , j=n-1
        
        int n=str.length();
        int i=0;
        int j=n-1;
        memset(dp,-1,sizeof(dp));
        return solve(str,i,j);
    }
};
