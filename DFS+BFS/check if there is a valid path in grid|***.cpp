
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:

    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:

Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

Example 2:

Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).

Example 4:

Input: grid = [[1,1,1,1,1,1,3]]
Output: true

Example 5:

Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    1 <= grid[i][j] <= 6

Accepted
14,132
Submissions
31,433
*****************
class Solution {
public:
    // time=0(mn)
    int x[4]={0,0,1,-1}; // dirns
    int y[4]={1,-1,0,0};
    // 2d turn array, 7 rows
    unordered_map<int,int> turns[7]{
                                    {},           // for 0th street
                                    {{0,0},{1,1}}, // for 1 street
                                    {{2,2},{3,3}}, // for 2 street
                                    {{3,1},{0,2}},
                                    {{3,0},{1,2}},
                                    {{0,3},{2,1}},
                                    {{2,0},{1,3}}
                                   }; 
   
    // 7 are the size for type of roads,and the next dimension is having turns
    
    // dir=0 (right),1(left),2(down),3(up)
    bool answer(vector<vector<int>> &grid,int dir)
    {
        int row=0, col=0;
        int n=grid.size();
        int m=grid[0].size();
        while(row>=0 && col>=0 && row<n && col<m)
        {
            auto road=grid[row][col];
            if(turns[road].count(dir)==0) // not present
                return false;
            if(row==n-1 && col==m-1) // found last position
                return true;
            
            dir=turns[road][dir]; // road={1,2,3,4,5,6}
            // dir={0,1,2,3}
            row=row+x[dir];
            col=col+y[dir];
            if(row==0 && col==0)
                return false;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        return answer(grid,0) || answer(grid,1) || answer(grid,2) || answer(grid,3);   // move in all 4 dirn from start
    }
};
