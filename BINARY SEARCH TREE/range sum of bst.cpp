Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

 

Example 1:

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32

Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23

 

Constraints:

    The number of nodes in the tree is in the range [1, 2 * 104].
    1 <= Node.val <= 105
    1 <= low <= high <= 105
    All Node.val are unique.

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
    // traverse the tree,and add the sum in range
    // time =0(n)
    // space=0(n)
    int sum=0;
    void findsum(TreeNode* root,int low,int high)
    {
        if(root==NULL)
            return;
        if(root->val>=low && root->val<=high){ // if in range
            sum+=root->val;
        findsum(root->left,low,high);
        findsum(root->right,low,high);
        }
        if(root->val > high)                   // if val is greater move left in bst
            findsum(root->left,low,high);
        if(root->val < low)                   // if val is less move right in bst
            findsum(root->right,low,high);
            
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        findsum(root,low,high);
        return sum;
    }
};
