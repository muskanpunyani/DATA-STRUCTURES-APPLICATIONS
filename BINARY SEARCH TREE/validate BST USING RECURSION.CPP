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
    bool validateBST(TreeNode* root,long long int min,long long int max)
    {
        if(root==NULL)
        {
            return true;
        }
        if((root->val)<min || (root->val) > max)
        {
            return false;
        }
        return validateBST(root->left,min,(root->val)-1) && validateBST(root->right,(root->val)+1,max);
    }
    bool isValidBST(TreeNode* root) {
     return validateBST(root,LLONG_MIN,LLONG_MAX);
        
    }
};
/* or we can also do it like this to avoid integer overflow
class Solution {
public:
    bool validateBST(TreeNode* root,long long int min,long long int max)
    {
        if(root==NULL)
        {
            return true;
        }
        if((root->val)<=min || (root->val) >=max)
        {
            return false;
        }
        return validateBST(root->left,min,(root->val)) && validateBST(root->right,(root->val),max);
    }
    bool isValidBST(TreeNode* root) {
     return validateBST(root,LLONG_MIN,LLONG_MAX);
        
    }
};
*/
