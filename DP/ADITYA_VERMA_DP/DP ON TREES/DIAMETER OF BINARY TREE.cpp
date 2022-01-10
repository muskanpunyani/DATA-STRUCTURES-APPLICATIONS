The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3

Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
*******************************
class Solution {
  public:
  // time=0(n)
  // space=0(h)
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root,int &res)
    {
        if(root==NULL)     // base
        return 0;
        
        // hypothesis
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        // induction
        // case 1- dont want to become ans
        int temp=1+max(l,r);
        // case 2 - want to become ans
        int ans=max(temp,l+r+1);
        // reinitialize result
        res=max(ans,res);
        return temp;  // returning the node that dont want to become ans so its passed further
        
    }
    int diameter(Node* root) {
        // max length netween two leafs
        int res=INT_MIN;
        solve(root,res);
        return res;         // res is passed as ans
    }
};
