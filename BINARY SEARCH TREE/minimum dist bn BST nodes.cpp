Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 105


************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
   inorder traversal
   time=0(n)
    */
    void minidiff(TreeNode* root,int &ans,TreeNode* &prev)
    {
        if(root==NULL)
            return;
         minidiff(root->left,ans,prev); // move left
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);  // mini
        }
        prev=root;
        minidiff(root->right,ans,prev); // move right
       
        
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        TreeNode* prev=NULL;
        minidiff(root,ans,prev);
        return ans;
    }
};
