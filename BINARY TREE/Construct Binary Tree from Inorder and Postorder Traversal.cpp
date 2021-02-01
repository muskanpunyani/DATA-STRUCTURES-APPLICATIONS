Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*****************************************************************************************************************************************
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
/* in inorder first right then left*/
//time=0(n)
class Solution {
public:
    
    /*int search(vector<int>& inorder,int start,int end,int value)
    {
        int i;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==value)
            {
                break;
            }
        }
        return i;
    }
    */
    unordered_map<int,int> m;
    TreeNode* buildutil(vector<int>& inorder,vector<int>& postorder,int start,int end,int* p_index)
    {
        if(start>end)
        {
            return NULL;
        }
        // now take out the last node of postorder,as last node will be root
        int curr=postorder[*p_index];
           TreeNode* node=new TreeNode(curr);  // taken that value out
        (*p_index)--;  // decrement the index for postorder array
        if(start==end)   // it means no chilren
        {
            return node;
        }
        // if thats not the case,search for the root in inorder array and deermine its left and right subtree
        int index=m[curr];   // find directly using map
        node->right=buildutil(inorder,postorder,index+1,end,p_index);
        node->left=buildutil(inorder,postorder,start,index-1,p_index);
      // node->right=buildutil(inorder,postorder,index+1,end,p_index,m);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();  // length of array
        int p_index=n-1;    // post order index
    // used map to store the index
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        return buildutil(inorder,postorder,0,inorder.size()-1,&p_index);
        
    }
};
