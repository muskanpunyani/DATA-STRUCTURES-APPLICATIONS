Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.

Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

 

Constraints:

    The number of nodes in the tree will be in the range [1, 500].
    0 <= Node.val <= 500
    The values of the nodes in the tree are unique.



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
/*
The thought process goes like this - Find all deepest nodes by traversing the tree using BFS. The required node is nothing but the LCA of all the deepest nodes. Finding LCA of all nodes at the same level is equivalent to finding LCA of the leftMost and rightMost node. Keep track of leftMost and rightMost nodes while doing BFS and finally return their LCA.

time=0(n)
*/
class Solution {
public:
    TreeNode* lca(TreeNode* root,TreeNode* l,TreeNode* r)
    {
        if(root==NULL)
            return root;
        if(l==root || r==root)
        {
            return root;
        }
        TreeNode* l1=lca(root->left,l,r);
        TreeNode* r1=lca(root->right,l,r);
        if(l1 && r1)
            return root;
        if(l1)
            return l1;
        if(r1)
            return r1;
        
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL)
            return root;
        TreeNode* leftmost=NULL;
        TreeNode* rightmost=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) // deepest nodes will be at last level
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(i==0)
                    leftmost=temp;
                if(i==n-1)
                    rightmost=temp;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        TreeNode* ans=lca(root,leftmost,rightmost);
        return ans;
    }
};
