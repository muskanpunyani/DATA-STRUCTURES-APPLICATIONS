Given an acyclic graph (n-ary tree) compute its pre-order traversal.

The graph has n nodes indexed 0 to n-1. It is given in the form of an adjacency list and you can consider the node indexed 0 to be the root.

Return the pre-order traversal starting at the root.
Example
dfs-of-acyclic-graph
Testing
Input Format

The first line contains an integer T denoting the number of test cases.

For each test case, the input has the following lines:

    The first line contains the integer n.
    The next n lines descibes the adjacent nodes for the ith node.
        The first integer m denotes the number of adjacent nodes.
        The next m integers denote adjacent nodes.

Output Format

For each test case, the output has one line with space-separated integers denoting the pre-order traversal.
Sample Input

2
7
3 1 3 6
3 0 2 4
1 1
1 0
2 1 5
1 4
1 0
2
1 1
1 0

Expected Output

0 1 2 4 5 3 6
0 1

Constraints

1 <= T <= 10
1 <= n <= 10000
0 <= m < n
*****************
void dfs(vector<vector<int>> &adjList,int start,vector<int>& ans,int parent)
{
	ans.push_back(start);
	for(auto it:adjList[start])
	{
		if(it!=parent)
		{
			dfs(adjList,it,ans,start);
		}
	}
}
vector<int> dfs(vector<vector<int>> &adjList) {
    // add your logic here
	/*
	 *     Start from the root node and add it to the answer array.
    Now traverse its adjacent nodes and for every node except the parent of the current root node, do the above steps recursively.
	bcz its a acyclic graph, same parent can be of multiple nodes
	 */
	vector<int> ans;
	dfs(adjList,0,ans,-1);
	return ans;
	
}
// time=0(v+e)
