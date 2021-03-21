In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

 

Constraints:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.



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
    pair<TreeNode*,int> bfs(TreeNode* root,int val)
    {
        pair<TreeNode*,int> ans; // ans is having parent and depth
        queue<TreeNode*>q;
        int depth=0;
        q.push(root);
        while(!q.empty())
        {
           int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->right && temp->right->val==val || temp->left && temp->left->val==val)
                {
                    ans={temp,depth+2};
                    return ans;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            depth++;
        }
        return ans;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*,int>x1,y1;
        x1=bfs(root,x);
        y1=bfs(root,y);
        if(x1.first!=y1.first && x1.second==y1.second) // if diff parent and same depth
        {
            return true;
        }
        return false;
    }
};
