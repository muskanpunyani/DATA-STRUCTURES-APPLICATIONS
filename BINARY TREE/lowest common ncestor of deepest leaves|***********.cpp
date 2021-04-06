Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

Note: This question is the same as 865: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.

Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.

 

Constraints:

    The number of nodes in the tree will be in the range [1, 1000].
    0 <= Node.val <= 1000
    The values of the nodes in the tree are unique.


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
class Solution {
public:
    /*
    we need to return the lca node and then whole subtree will be returned as in first eg 
    */
    /*
    1] the most common soln is find the two corner nodes at deepest level using bfs,
    we will find the first and last node at every level and in this way at last we will have the nodes last level
    then apply lca algorithm on those 2 nodes and return ans
    */
    /*
    2] deepest leaves lca
    we can find the deepest ht and the lca will be found in the same flow while recurring
    see code for better understanding
     time=0(n)
     space=0(h)
    */
    TreeNode* lca;
    int deepest=0;
    int finddepth(TreeNode* root,int depth)
    {
        if(root==NULL){                  // if we reached end then we can update deepest
            deepest=max(deepest,depth);  // find max depth 
            return depth;                // if root is null,max thing to be returned is the depth till that point
        }
        int l=finddepth(root->left,depth+1);  
        int r=finddepth(root->right,depth+1); 
        if(l==deepest && r==deepest )  // if l and r are deepest,lca is root
        {
            // if suppose root->left or root->right is null then l or r may go to our base case and it will return depth.
            // if leaf is lca ,i.e both left and right are null then both l r will return same depth and thus the ans is that leaf node
            lca=root;
        }
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth=0;
        finddepth(root,depth);
        return lca;
    }
};
