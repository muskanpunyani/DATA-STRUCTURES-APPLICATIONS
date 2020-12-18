Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

Follow up: Can you solve it with time complexity O(height of tree)?

 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:

Input: root = [], key = 0
Output: []
*********************************************************************************************************************************
1) if 0 or no child,del it directly
2) if 2 child,find inorder successor,
inorder successor is finding min val element in the right subtree,greater than root value.
repalce that with root to be deleted and delete the inorder

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){     // if root val is key
            if(root->right==NULL){  // if it has only 1 child or 0 child
                return root->left;
            }
            TreeNode* tmp = root->right;
            while(tmp->left){    // finding inorder successor
                tmp = tmp->left;
            }
            tmp->left=root->left;  // swapping values
            return root->right;     
        }
        if(root->val>key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};
