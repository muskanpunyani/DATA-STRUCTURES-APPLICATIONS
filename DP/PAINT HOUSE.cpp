Problem Description

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.


Problem Constraints

1 <= N <= 105

1 <= A[i][j] <= 103


Input Format

First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.


Output Format

Return an integer denoting the minimum total cost to paint all houses.


Example Input

Input 1:

 A = [  [1, 2, 3]
        [10, 11, 12]
     ]



Example Output

Output 1:

 12



Example Explanation

Explanation 1:

 Paint house 1 with red and house 2 with green i.e A[0][0] + A[1][1] = 1 + 11 = 12



Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
**********************
/*
if i am considering color red for first, color green and blue can be taken for i-1
similar for other colors
final row will have all the color options , if red green or blue is taken 
minuimum of that row would be ans

Let:

    dp[i][0] represent the minimum total cost to paint the houses till i where house i is colored in red.
    dp[i][1] represent the minimum total cost to paint the houses till i where house i is colored in green.
    dp[i][2] represent the minimum total cost to paint the houses till i where house i is colored in blue.

So if you paint house ‘i’ with red then you can paint house ‘i-1’ only in blue or green.
So dp[i][0] = A[i][0] + min(dp[i-1][1],dp[i-1][2])
Similarly:
dp[i][1] = A[i][1] + min(dp[i-1][0], dp[i-1][2])
dp[i][2] = A[i][2] + min(dp[i-1][0], dp[i-1][1])

At last output the minimum of (dp[n-1][0],dp[n-1][1],dp[n-2][2)

Time Complexity:O(N).
*/
int Solution::solve(vector<vector<int> > &A) {
    int N=A.size();
    for(int i=1;i<N;i++)
    {
        A[i][0]=A[i][0]+min(A[i-1][1],A[i-1][2]);
        A[i][1]=A[i][1]+min(A[i-1][0],A[i-1][2]);
        A[i][2]=A[i][2]+min(A[i-1][0],A[i-1][1]);
    }
    int ans=INT_MAX;
    for(int i=0;i<3;i++)
    {
        ans=min(ans,A[N-1][i]);
    }
    return ans;
}
