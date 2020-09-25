Given a binary tree

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

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to i
************************************************************************************************************************************************
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/* This can't be done same as for perfect binary tree,as it can have many children,therefore we need
to find every node link ad thus the solution will be different
this soln will also be accepted for perfect binary tree
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(!root) return root;
        q.push(root);   // pushing root and null
        q.push(NULL);
        root->next = NULL;
        while(!q.empty()){
            Node* temp = q.front();  
            q.pop();
            if(temp){     
                temp->next = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
           else if(!q.empty())
             q.push(NULL);
        }
        return root;
    }
};
