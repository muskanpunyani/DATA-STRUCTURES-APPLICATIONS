We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.

 

Example 1:

Input: S = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:

Input: S = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:

Input: S = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

 

Constraints:

    The number of nodes in the original tree is in the range [1, 1000].
    1 <= Node.val <= 109


************************
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
    the output is in for of bfs level by level
    we need to return the root
    */
    /*
    the idea is simple:
go through the string only once and each time when we reach a none root number (a node), it is the left or right child of the last appeared number (node) whose number of dashes is 1 less than the current one's.

use a map with the key being the number of dashes of each node.
    */
    // time=space=0(n)
    map<int,TreeNode*> m; // count of '-'  for every node, i.e level-node
    TreeNode* recoverFromPreorder(string s) {
        int level=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='-')
            {
                level++;
            }
            else{ // number
                string num="";
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    num+=s[i];
                    i++;
                }
                i--;    //  because if we don't do i-- then what happen is after calculating num when we go to for loop then i is again incremented so the total number of time i is incremented by 2 i.e. i+=2 one during calculating num and second when we go to for loop. so for preventing this we do i--- that means now at next step i is only incremented by one. that we want to access.
                int number=stoi(num);
                m[level]=new TreeNode(number);
                if(level>0 && m[level-1]->left)
                    m[level-1]->right=m[level];
                else if(level>0 && !m[level-1]->left) // if not having left child,this will be a left child
                    m[level-1]->left=m[level];
                
                level=0;  // again calculation for new dashes
                
            }
        }
        return m[0];  // at level 0 is root
    }
};
