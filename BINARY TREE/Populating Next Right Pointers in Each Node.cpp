You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

    You may only use constant extra space.
    Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

 

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

 

Constraints:

    The number of nodes in the given tree is less than 4096.
    -1000 <= node.val <= 1000

********************************************************************************************************************************************8
class Solution {
public:
    Node* connect(Node* n) {
        //if n is null, return NULL;
        if (n==NULL) {
            return NULL;
        }
        //if it is a left child, and it's a balanced tree, we could point to the right child
        if (n->left && n->right) {
            n->left->next = n->right;
        } 
		//if it is right child and its parent has next node, we should point to the left child of next node
        if (n->right && n->next) {
                n->right->next = n->next->left;
        }
    
		
        //connect left and right child recursively
        connect(n->left);
        connect(n->right);
        
        return n;
    } 
};
