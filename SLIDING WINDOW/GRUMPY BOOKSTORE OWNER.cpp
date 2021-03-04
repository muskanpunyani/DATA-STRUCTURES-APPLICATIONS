Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

 

Note:

    1 <= X <= customers.length == grumpy.length <= 20000
    0 <= customers[i] <= 1000
    0 <= grumpy[i] <= 1

*************************
class Solution {
public:
    /*
    1] if the owner is not grumpy ,customers are satisfied.
    that is satisfy=sum of all numbers when not grumpy
    2] when owner is grumpy,we will use sliding window,
    just add the values in a variable grumpy_satisfied and move forward,i.e increase the window sizze
    if the window becomes greater than x,reduce the window size by removing elem from start
    in all these process,keep track of max length of window and add it to satisfied before returning ans
    */
    // time=0(n)
    // space=0(1)
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n=customers.size();
        int satisfied=0;
        int grumpysatisfied=0;
        int grump_start=0;
        int grump_end=0;
        int additional_satisfaction_grumpy=0;  
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                satisfied+=customers[i];
            }
        }
        // sliding window
        for(grump_end=0;grump_end<n;grump_end++)
        {
            if(grumpy[grump_end]==1) // add grumpy ones
            {
            grumpysatisfied+=customers[grump_end];
            }
            if(grump_end-grump_start +1 > X)
            {
                if(grumpy[grump_start]==1) // subtract only if grumpy
                {
                    grumpysatisfied-=customers[grump_start];
                }
                grump_start++;
            }
            additional_satisfaction_grumpy=max(grumpysatisfied,additional_satisfaction_grumpy);
        }
        int ans=satisfied+additional_satisfaction_grumpy;
        return ans;
    }
};
