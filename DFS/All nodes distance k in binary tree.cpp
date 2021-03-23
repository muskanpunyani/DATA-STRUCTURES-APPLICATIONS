We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

*************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    At distance k from target node
    1] can be children
    2] or can be parent
    
    finding children at dist k is easy but for parent we can keep a map to store parent of every node
    
    // time=0(n)
    */
    map<TreeNode*,TreeNode*> parent;
    vector<int> ans;
    set<TreeNode*> visited;
    void findparent(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            parent[root->left]=root;
            findparent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            findparent(root->right);
        }
    }
    void dfs(TreeNode* target,int k)
    {
        if(visited.find(target)!=visited.end()) // if occured before
            return;
        
        visited.insert(target);
        if(k==0){   // if kth dist
            ans.push_back(target->val);
            return;
        }
        if(target->left)
        {
            dfs(target->left,k-1);
        }
        if(target->right)
        {
            dfs(target->right,k-1);
        }
        TreeNode* temp=parent[target];
        if(temp)
            dfs(temp,k-1);
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return {};
        findparent(root); // create parent
        dfs(target,k);  // dfs on target
        return ans;
    }
};
