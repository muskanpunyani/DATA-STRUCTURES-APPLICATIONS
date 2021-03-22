Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:

Input: root = [1,2,3]
Output: [1,3]

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,null,2]
Output: [1,2]

Example 5:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree will be in the range [0, 104].
    -231 <= Node.val <= 231 - 1



**********************
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
    // normal bfs
    // 0(n)
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                maxi=max(maxi,temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
