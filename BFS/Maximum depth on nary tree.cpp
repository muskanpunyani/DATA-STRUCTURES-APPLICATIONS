https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

 

Constraints:

    The depth of the n-ary tree is less than or equal to 1000.
    The total number of nodes is between [0, 104].

**************************************************************************

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
we can use bfs,return till queue is empty
time=0(n)
space=0(n)
*/

class Solution {
public:
    int maxDepth(Node* root) {
      int depth=0;
      if(root==NULL)
            return 0;
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      {
         
          int s=q.size();
          for(int i=0;i<s;i++)  // every depth
          {
              Node* temp=q.front();
              q.pop();
              for(Node* child:temp->children) // push child
              {
                  if(child)
                      q.push(child);
              }
          }
          depth++; // increment after every level
      }
        return depth;
        
    }
};
