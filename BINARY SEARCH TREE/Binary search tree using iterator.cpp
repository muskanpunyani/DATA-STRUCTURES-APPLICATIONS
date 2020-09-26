Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false

 

Note:

    next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
    You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.

**********************************************************************************************************************************************************8
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
class BSTIterator {
public:
    vector<int> v; // for storing inorder
    void findinorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        findinorder(root->right);  // here 1st right is taken bcz in vector deleting from last takes 0(1) 
        // and thus smallest will be at last and it will be time efficient
        // i.e vector will have greater to smaller
        v.push_back(root->val);
        findinorder(root->left);
    }
    BSTIterator(TreeNode* root) {
        findinorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int val=v.back();
        v.pop_back();
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        int l=v.size();
        if(l>0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
