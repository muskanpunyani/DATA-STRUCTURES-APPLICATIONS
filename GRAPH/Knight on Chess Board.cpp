

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.


Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).

Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.

Constraints:

1 <= A, B <= 500

Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.

*************************************************************************************************************************************

bool isvalid(int x, int y, int A, int B){
    if(x>=0 && x<A && y>=0 && y<B){
        return true;
    }
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int,int>> q;
    q.push(make_pair(C-1,D-1));  // as it is 1 based indexing,making it 0 based
    int dist[A][B];               // dist arr to store dist
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            dist[i][j]=INT_MAX;
        }
    }
    dist[C-1][D-1]=0;    // initially dist=0
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        // pushing all 8 directions (i.e 8 moves)
        if(isvalid(x+1,y+2,A,B) && dist[x+1][y+2]==INT_MAX){
            q.push(make_pair(x+1,y+2));
            dist[x+1][y+2]=dist[x][y]+1;     // distance +1 as move 1 move is increased
        }
        if(isvalid(x+1,y-2,A,B) && dist[x+1][y-2]==INT_MAX){
            q.push(make_pair(x+1,y-2));
            dist[x+1][y-2]=dist[x][y]+1;
        }
        if(isvalid(x+2,y+1,A,B) && dist[x+2][y+1]==INT_MAX){
            q.push(make_pair(x+2,y+1));
            dist[x+2][y+1]=dist[x][y]+1;
        }
        if(isvalid(x+2,y-1,A,B) && dist[x+2][y-1]==INT_MAX){
            q.push(make_pair(x+2,y-1));
            dist[x+2][y-1]=dist[x][y]+1;
        }
        if(isvalid(x-1,y+2,A,B) && dist[x-1][y+2]==INT_MAX){
            q.push(make_pair(x-1,y+2));
            dist[x-1][y+2]=dist[x][y]+1;
        }
        if(isvalid(x-1,y-2,A,B) && dist[x-1][y-2]==INT_MAX){
            q.push(make_pair(x-1,y-2));
            dist[x-1][y-2]=dist[x][y]+1;
        }
        if(isvalid(x-2,y+1,A,B) && dist[x-2][y+1]==INT_MAX){
            q.push(make_pair(x-2,y+1));
            dist[x-2][y+1]=dist[x][y]+1;
        }
        if(isvalid(x-2,y-1,A,B) && dist[x-2][y-1]==INT_MAX){
            q.push(make_pair(x-2,y-1));
            dist[x-2][y-1]=dist[x][y]+1;
        }

    }
    // here we are finding distance from source to every possible box,and finally checking the distance of required block
    // used dp here
    if(dist[E-1][F-1]==INT_MAX){
        return -1;
    }
    else{
        return dist[E-1][F-1];
    }
}

