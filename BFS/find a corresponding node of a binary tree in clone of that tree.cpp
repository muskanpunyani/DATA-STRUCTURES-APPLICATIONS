https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /*
    1] traverse both trees t same time and when we find target in original return target from cloned
    if values are repeated we can compare the nodes
    */
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> o;
        queue<TreeNode*> c;
        o.push(original);
        c.push(cloned);
        while(!o.empty() && !c.empty())
        {
            TreeNode* t1=o.front();
            o.pop();
            TreeNode* t2=c.front();
            c.pop();
            if(t1==target) // comparing nodes,in case of repeated val
            {
                return t2;
            }
            if(t1->left)
            {
                o.push(t1->left);
                c.push(t2->left);
            }
            if(t1->right)
            {
                o.push(t1->right);
                c.push(t2->right);
            }
        }
        return NULL;
    }
};
