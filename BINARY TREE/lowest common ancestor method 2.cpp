/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
if the p is in left subtree and q in right,then root wil be lca
if p is only in left subtree the lca will be in left subtree
else lca will be in right subtree
*/
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<int> path1,path2;
        TreeNode* temp;
        if(root==NULL)
        {
            return temp;
        }
        if(root->val==p->val || root->val==q->val)  // if root val matches with any of required node,then that is lca
        {
            return root;
        }
        TreeNode* left_lca=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_lca=lowestCommonAncestor(root->right,p,q);
        if(left_lca && right_lca)   // if both left n right are null then root is lca
        {
            return root;
        }
        if(left_lca)
        {
            return left_lca;
        }
        if(right_lca)
        {
            return right_lca;
        }
        return temp;
    }
};
