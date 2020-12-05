Given a binary tree, find its minimum depth.

Example 1:

Input:
            1
          /   \
         3     2
        /
       4           

Output: 2

Explanation:
Minimum depth is between nodes 1 and 3.

Example 2:

Input:
             10
          /     \
        20       30
          \        \   
          40        60 
                   /
                  2 

Output: 3

Explanation:
Minimum depth is between nodes 10,20 and 40.


Your Task:  
You dont need to read input or print anything. Complete the function minDepth() which takes root node as input parameter and returns the minimum depth.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

*******************************************
int minDepth(Node *node) {
 /* we will do level order traversal and the first leaf node found depth is returned
 */
 queue<pair<Node*,int>> q; // pair of int and depth
 q.push({node,1});
 while(!q.empty())
 {
     pair<Node*,int> p=q.front();
     q.pop();
     Node* root=p.first;
     int depth=p.second;
     if(root->left==NULL && root->right==NULL) // leaf node
     {
         return depth;
     }
     if(root->left) 
     {
         //depth=depth+1;
         q.push({root->left,depth+1});
     }
     if(root->right)
     {
         q.push({root->right,depth+1});
     }
 }
 return -1;
}
