Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
Example 3:

Input: n = 2, k = 0
Output: [11,22,33,44,55,66,77,88,99]
Example 4:

Input: n = 2, k = 2
Output: [13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
 

Constraints:

2 <= n <= 9
0 <= k <= 9
*************************************
class Solution {
public:
    /*
    n=3,k=7
    means we want 3 digit numbers with diff bn every adjacent digit =7
    
    
    eg n=3,k=2
    1st digit= lets say 1
    2nd digit=(1+k)(1-k); i.e 3,-2; -2 is not in range [0,9] thus 2nd digit=3
    3rd digit=(3+k)(3-k);  i.e 5,1.....
    thus
                 1
                 |
                 3
                /  \
                5   1
                
    thus 2 numbers are [1,3,5][1,3,1] starting ffrom 1
    thus this problem is reduced to finding the number from a tree in its root to leaf path
    */
    /*
    Time Complexity: \mathcal{O}(2^{N})O(2 
N
 )

Essentially, the execution of the algorithm will unfolder itself as a binary tree, where each node in the tree represents an invocation of the DFS() function. The execution of the DFS() function itself takes a constant time. Therefore, the overall time complexity is proportional to the number of nodes in the execution binary tree.

In the worst case, the total number of nodes in a binary tree of depth N-1N−1 is 2^N2 
N
 . Hence, the overall time complexity of the algorithm is \mathcal{O}(2^{N})O(2 
N
 ).

Note that, when K = 0K=0, at each position, there is only one possible candidate, e.g. 333333. In total, we would have 9 numbers in the result set, and each number is of NN digits. The time complexity would then be reduced down to \mathcal{O}(N)O(N).

Space Complexity: \mathcal{O}(2^{N})O(2 
N
 )

Since we adopt a recursive solution, we would have some additional memory consumption on the function call stack. The maximum number of consecutive calls on the recursion function is NN. Hence, the space complexity for the call stack is \mathcal{O}(N)O(N).

We use a list to keep all the solutions, which could amount to 9 \cdot 2^{N-1}9⋅2 
N−1
  number of elements.

To sum up, the overall space complexity of the algorithm is \mathcal{O}(N) + \mathcal{O}(9 \cdot 2^{N-1}) = \mathcal{O}(2^{N})O(N)+O(9⋅2 
N−1
 )=O(2 
N
 ).
    */
    void dfs(int n,int num,int k,vector<int>& ans)
    {
        if(n==0)
        {
            ans.push_back(num);
            return;
        }
        int lastdigit=num%10;
        int nextdigit1=lastdigit+k;
        int nextdigit2;
        if(k!=0){   // bcz for k=0,+k and -k ans will be same thus repeated values eg for 1 as first digit and k=0 , 1+k=1-k=1 thus "11" two times
         nextdigit2=lastdigit-k;
        }
        if(nextdigit1>=0 && nextdigit1<=9)
        {
            int temp_num=num*10+nextdigit1;
            dfs(n-1,temp_num,k,ans);   // recurse
        }
        if(nextdigit2>=0 && nextdigit2<=9)
        {
            int temp_num=num*10+nextdigit2;
            dfs(n-1,temp_num,k,ans);    // recurse
        }
        
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1)
        {
            return {0,1,2,3,4,5,6,7,8,9};
        }
        vector<int> ans;
            for(int num=1;num<10;num++) // taking first digit from 1 to 9
            {
                dfs(n-1,num,k,ans);
            }
        return ans;
    }
};
