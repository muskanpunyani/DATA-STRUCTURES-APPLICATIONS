Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

 

Constraints:

    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    to_delete.length <= 1000
    to_delete contains distinct values between 1 and 1000.


*****************************************
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
    if a node is a root(i.e no parent) and is not getting deleted then add it to result
    result will contain only roots of independent parts
    */
    // time=0(n)
    // space=0(h+n)
    set<int> deleted;     // to check for deleted nodes directly
    vector<TreeNode*> res;
    TreeNode* findanswer(TreeNode* root,bool isroot)
    {
        if(root==NULL)
            return NULL;
        bool isdeleted=(deleted.find(root->val)!=deleted.end()); // check if the root is a node to be deleted
        if(isroot && !isdeleted) // if root and not a node to be deleted
        {
            res.push_back(root);
        }
        /* creating tree by going left n right,ans isdeleted for isroot bcz,if isdeleted for the root is true,hthen root->left will be root as its parent will be deleted,so true for that else false
        */
        root->left=findanswer(root->left,isdeleted);
        root->right=findanswer(root->right,isdeleted);
        
        if(isdeleted)  // if root is deleted cant return it
            return NULL;
        return root;  
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++)
        {
            deleted.insert(to_delete[i]);
        }
        bool isroot=true;  // initially given node is root
        findanswer(root,isroot);
        return res;
    }
};
