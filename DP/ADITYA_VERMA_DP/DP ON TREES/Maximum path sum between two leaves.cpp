Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.


Example 1:

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

Example 2:

Input:    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  
Output:  27
Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)


Your Task:  
You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)


Constraints:
2  ≤  Number of nodes  ≤  104
-103  ≤ Value of each node ≤ 103
******************************
class Solution {
public:
int solve(Node* root,int &res)
    {
        // base
        if(root==NULL)
          return 0;
        // base 2
        if(root->left==NULL && root->right==NULL)
        {
            return root->data;
        }
        //hypothesis
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
       // induction
       if(root->left && root->right)  // if we have both l and r
       {
        // case 1, dont want to become ans
        int temp=max(l,r)+root->data;
        // case 2 want to become ans
        int ans=(l+r+root->data);
        
        // res
        res=max(res,ans);
        
        return temp;
       }
       // if only left
       if(root->right==NULL)
       {
           return (l+root->data);
       }
       if(root->left==NULL)
       {
           return (r+root->data);
       }
        
        
    }
    int maxPathSum(Node* root)
    {
        int res=INT_MIN;
        int ans=solve(root,res);
        /*
        There is one boundary condition that we need to take care about.
        If the tree is a skew tree (only have either left child or right child), 
        the res variable would remain INT_MIN thought and never change.
        So in the end check if answer is equal to INT_MIN.
        If true, return the answer that is stored in the variable you used while calling helper function.
        */
        if(res!=INT_MIN)
        return res;
        else
        return ans;
    }
};
