Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

 

Constraints:

    The number of nodes in the tree is in the range [0, 105].
    -1000 <= Node.val <= 1000


******************
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
    bfs
    0(n)
    the first leaf node is min depth
    */
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL)
            return 0;
        int depth=0;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL)
                {
                    return depth+1;
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            depth++;
        }
return depth;
   }
};
