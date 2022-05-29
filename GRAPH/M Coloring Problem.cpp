ou are given an undirected graph with n nodes and an integer m.

Find if it is possible to color all the vertices of the graph using atmost m colors, such that no two adjacent vertices have the same color.

Note: You are given the graph in the form of an adjacency matrix adjMatrix of size n*n.
adjMatrixij = 1 means there is an edge between nodes i and j.
Example:
m-coloring-problem
Testing
Input Format

The first line contains an integer ‘T’ denoting the number of test cases.

For each test case the input has the following lines:

    Two space-separated integers 'n' and 'm' denoting the number of nodes and available colors.
    n lines, each containing n space-separated numbers making up the adjacency matrix.

Output Format

For each test case, the output has a line with 1 or 0, denoting if valid coloring is possible or not.
Sample Input

3
4 3
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
4 2
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
3 3
1 1 1
1 1 1
1 1 1

Expected Output

1
0
0

Constraints

1 <= T <= 10
1 <= n, m <= 20
0 <= adjMatrixij <= 1
*******************
// time=0(m^n)
bool issafe(vector<vector<int>>& adjMatrix,vector<int>& color,int j,int vertex,int n)
{
	// if edge bn anotther node and same color then false
	for(int i=0;i<n;i++)
	{
		if(adjMatrix[vertex][i]==1 && color[i]==j)
		{
			return false;
		}
	
		
	}
		return true;
}
bool solve(vector<vector<int>>& adjMatrix,vector<int>& color,int m,int n,int vertex)
{
	if(vertex==n)   // if all vertex is covered
		return true;
	// all colour 
	for(int j=1;j<=m;j++)
	{
	if(issafe(adjMatrix,color,j,vertex,n))  //safe to color
	{
		color[vertex]=j;  // mark it
		// recurse for next vertex
		if(solve(adjMatrix,color,m,n,vertex+1)) 
		{
			return true;
		}
		color[vertex]=0; // backtrack
	}

		}
	return false; // 
}
bool isColoringPossible(vector<vector<int>> &adjMatrix, int m) {
    // add your logic here
	/*
	 we will go to every node and check every color from 1 to m if possible
	 not safe case - we are coloring with some x and there is an edge with other node having same color x so it would return false
	 */
	int n=adjMatrix.size();
	vector<int> color(n+1,0);
	// if there is loop to the same
	for(int i=0;i<n;i++){
	if(adjMatrix[i][i])
	{
		return false;
	}
	}
	
	return solve(adjMatrix,color,m,n,0);
}
