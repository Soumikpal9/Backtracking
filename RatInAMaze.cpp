/*

        Problem Description

        Given a grid A, a rat is at position (1, 1). He wants to go to the position (n, n) where n is size of the square matrix A.

        1 represents a traversable cell and 0 represents a non-traversable cell. Rat can only move right or down.

        Return a path that the rat can take.



        Problem Constraints

        1 <= |A| <= 4



        Input Format

        First and only argument is the vector of vectors A.



        Output Format

        Return a vector of vectors that denotes a path that can be taken.



        Example Input

        Input 1:

        A = [   [1, 0]
                [1, 1]
            ]
        Input 2:

        A = [    [1, 1, 1]
                [1, 0, 1]
                [0, 0, 1]
            ]


        Example Output

        Output 1:

        [   [1, 0]
            [1, 1]
        ]
        Output 2:

        [    [1, 1, 1]
            [0, 0, 1]
            [0, 0, 1]
        ]


        Example Explanation

        Explanation 1:

        Path is shown in output.
        Explanation 2:

        Path is shown in output.

*/

void ratInAMaze(int i, int j, vector<vector<int>> &A, int n, string &ans, string move, vector<vector<int>> &vis, int di, int dj){
    if(i==n-1 && j==n-1){
        ans=move;
        return;
    }
    string dir="DLRU";
    for(int ind=0;ind<4;ind++){
        int nexti=i+di[ind];
        int nextj=j+dj[ind];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && A[nexti][nextj]==1){
            vis[i][j]=1;
            ratInAMaze(nexti, nextj, A, n, ans, move+dir[ind], vis, di, dj);
            vis[i][j]=0;
        }
    }
}

vector<vector<int>> Solution::solve(vector<vector<int>> &A){
    string ans="";
    vector<vector<int>> vis(A.size(), vector<int> (A.size(), 0));
    int di[]={1, 0, 0, -1};
    int dj[]={0, -1, 1, 0};
    if(A[0][0]==1){
        ratInAMaze(0, 0, A, A.size(), ans, "", vis, di, dj);
    }
    vis[0][0]=1;
    vis[A.size()-1][A.size()-1]=1;
    int i=0, j=0;
    for(int k=0;k<ans.size();k++){
        if(ans[k]=='D'){
            vis[i+1][j]=1;
            i++;
        }
        else if(ans[k]=='L'){
            vis[i][j-1]=1;
            j--;
        }
        else if(ans[k]=='R'){
            vis[i][j+1]=1;
            j++;
        }
        else{
            vis[i-1][j]=1;
            i--;
        }
    }
    return vis;
}