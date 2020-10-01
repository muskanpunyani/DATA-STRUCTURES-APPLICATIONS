

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
***********************************************************************************************************************************************

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int sol(TreeNode* A,int value)
 {
     if(A==NULL)
     return 0;
     
     int temp=(((10*value)%1003)+(A->val))%1003;
     if(A->left==NULL && A->right==NULL)
     {
         return temp%1003;
     }
   int l=  sol(A->left,temp);    // passing temp as val,means it will be multiplied*10+val
     int r=sol(A->right,temp);
     return (l+r)%1003;
 }
 
int Solution::sumNumbers(TreeNode* A) {
  return sol(A,0);  
}
