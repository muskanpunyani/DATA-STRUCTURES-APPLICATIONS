You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island
(i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
 One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]                                   0 1 0 0  // the perimeter for [1]=4,if it is surrounded by more
                                                                                          1 1 1 0  // ones then perimeter will be 4-(no of surrounding ones) 
                                                                                          0 1 0 0  // eg 1 1 => for first 1 perim=3, 2nd =3,total=6 
                                                                                          1 1 0 0
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 100
    grid[i][j] is 0 or 1.

******************************************************************************************
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int perimeter=0;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
               
                if(grid[i][j]==1)    // if land,check surrounding 1's in 4 dirn
                {
                     int no_of_ones=0;
                    if(i-1>=0 && grid[i-1][j]==1)       // prev row
                        no_of_ones++;
                    if(i+1<n && grid[i+1][j]==1)        // next row
                        no_of_ones++;
                    if(j-1>=0 && grid[i][j-1]==1)        // prev col
                        no_of_ones++;
                    if(j+1<m && grid[i][j+1]==1)         // next col
                        no_of_ones++;
                    
                    perimeter=perimeter+(4 - no_of_ones);
                    
                }
            }
        }
        return perimeter;
    }
};
