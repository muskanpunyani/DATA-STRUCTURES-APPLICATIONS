Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

******************************************************************************************************************************8

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
/* in preorder we will have starting vertex as root,rest all is same as post order one*/
class Solution {
public:
    unordered_map<int,int> m;
    TreeNode* buildutil(vector<int>& preorder,vector<int>& inorder,int start,int end,int* p_index)
    {
        if(start>end)
         return NULL;
        int curr=preorder[*p_index];
        TreeNode* node=new TreeNode(curr);
        (*p_index)++;
        if(start==end)
        {
            return node;
        }
        int index=m[curr];
        node->left=buildutil(preorder,inorder,start,index-1,p_index);
        node->right=buildutil(preorder,inorder,index+1,end,p_index);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int p_index=0;   // in preorder first elemnt is root
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;  // storing index
        }
        return buildutil(preorder,inorder,0,inorder.size()-1,&p_index);
        
    }
};
