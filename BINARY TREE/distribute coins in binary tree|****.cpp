You are given the root of a binary tree with n nodes where each node in the tree has node.val coins and there are n coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another. (A move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

 

Example 1:

Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:

Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to the right child.

Example 3:

Input: root = [1,0,2]
Output: 2

Example 4:

Input: root = [1,0,0,null,3]
Output: 4

 

Constraints:

    The number of nodes in the tree is n.
    1 <= n <= 100
    0 <= Node.val <= n
    The sum of Node.val is n.



***********************************
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
number of moves is equal to abs sum of excess value at every node
excess value at every node=node->val-1 , if 0 it will be -1 thus abs
*/
/*

    Root asks the left subtree, how much do you need or you've got extra? I'll give that/take it away to/from you via our direct edge, and pass it to right child, and if something remains, I'll take it.
    Same question is asked to the right child.
    Answer will be the sum of values(absolute) returned after the asked questions from the left(Left) and right(Right).
    But what should the root return to its parent? It will return that how much does "his tree" need/has extra. That will be the signed sum of its Left+Right (question's answer) + same question asked to current root node.

*/
/*
Complexity Analysis

    Time Complexity: O(N), where N is the number of nodes in the tree.

    Space Complexity: O(H), where H is the height of the tree.
*/
class Solution {
public:
    int ans=0;
    int findmoves(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=findmoves(root->left);  // excess left
        int r=findmoves(root->right); // excess right
        ans+=abs(l)+abs(r); // excess value is no of moves
        return root->val+l+r-1;  // excess value
        
    }
    int distributeCoins(TreeNode* root) {
        findmoves(root);
        return ans;
    }
};
