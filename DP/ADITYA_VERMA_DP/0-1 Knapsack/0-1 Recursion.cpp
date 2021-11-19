You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*************************
// complexity = exponential

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // recursion code
       // 2 choices if wt is less than total W; can take that elem or not take
       // 1 choice if wt is  greater than W, don't take
       // need max values of max options
       
       if(n==0 || W==0) // if size of bag is 0 or no elements max ans  could be 0
       {
           return 0;
       }
       if(wt[n-1]<=W)
       {
           // 2 choices
           int opt1=val[n-1]+knapSack(W-wt[n-1],wt,val,n-1);  // consider element and add its value, subtract its weight; recures for rest
           
           // dont consider
           int opt2=knapSack(W,wt,val,n-1);
           
           return max(opt1,opt2);
       }
       else{
           // 1 choice ; dont consider
           return knapSack(W,wt,val,n-1);
       }
    }
};
