Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:

Input: root1 = [1], root2 = [1]
Output: true

Example 3:

Input: root1 = [1], root2 = [2]
Output: false

Example 4:

Input: root1 = [1,2], root2 = [2,2]
Output: true

Example 5:

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

 

Constraints:

    The number of nodes in each tree will be in the range [1, 200].
    Both of the given trees will have values in the range [0, 200]
*****************************
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
// time=0(t1+t2),where t1 and t2 are length of given trees
// space=0(t1+t2)
class Solution {
public:
    void findleaf(vector<int>& v,TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
        }
        if(root->left)
            findleaf(v,root->left);
        if(root->right)
            findleaf(v,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1; // leaf node for t1
        vector<int> tree2; // leaf nodes for t2
        findleaf(tree1,root1);
        findleaf(tree2,root2);
        if(tree1==tree2)
        {
            return true;
        }
        return false;
            
    }
};
