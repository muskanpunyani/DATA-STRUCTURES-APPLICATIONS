Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints

1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format

First and only argument is a 2D matrix A.


Output Format

Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.


Example Input

Input 1:

 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]

Input 2:

 A = [
       [2, 2]
       [2, 2]
     ]



Example Output

Output 1:

 7

Output 2:

 4



Example Explanation

Explanation 1:

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:

 Water can flow from all cells.
 *************************************************************************************************************************************************



int n,m;
void dfs(vector<vector<int> >&A,vector<vector<int> > &visited,int i,int j,int label,int &count,int prev)
{
    // prev is used bcz the next elemnt while traversig should have height greater or equal than previous
    // visited[i][j]=label means that elem is already visited,need not check it again
    if(i>=n || j>=m || i<0 || j<0 || visited[i][j]==3 || A[i][j]<prev || visited[i][j]==label)
    return ;
    
    visited[i][j]+=label;
    if(visited[i][j]==3)  // increasing count here bcz,when blue lake comes,visited becomes 1
    // when red comes,visited is incremented by 2,i.e when visited is 3 both lakes dfs is having that element as common thus count is incremented by 1.
    {
        count=count+1;
    }
    dfs(A,visited,i+1,j,label,count,A[i][j]);
    dfs(A,visited,i-1,j,label,count,A[i][j]);
    dfs(A,visited,i,j+1,label,count,A[i][j]);
    dfs(A,visited,i,j-1,label,count,A[i][j]);
}
int Solution::solve(vector<vector<int> > &A) {
  /* we will do dfs from blue as well as red lake and will find the visited array,
  the common no of visited elements will be by both blue and red lake and thus the count
  */
  int count=0;
  n=A.size();
   m=A[0].size();  //col
  vector<vector<int>> visited(n,vector<int>(m,0));  // initially all rows are zero
  for(int i=0;i<m;i++)  // columns
  {
      dfs(A,visited,0,i,1,count,INT_MIN);  // 0th row,every colum,blue lake(label=1)
      dfs(A,visited,n-1,i,2,count,INT_MIN);  // last row,every column,red lake(label=2)
  }
  for(int i=0;i<n;i++) // rows
  {
       dfs(A,visited,i,0,1,count,INT_MIN); // 1st col ,blue lake
        dfs(A,visited,i,m-1,2,count,INT_MIN);  // last col,red lake
      
  }
  return count;
  
    }
