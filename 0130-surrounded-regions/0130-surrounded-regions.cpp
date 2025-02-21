class Solution {
public:
void solve1(vector<vector<char>>&grid,int i,int j){
    if(i-1>=0 && grid[i-1][j]=='O'){
        grid[i-1][j]='@';
        solve1(grid,i-1,j);
    }
    if(j-1>=0 && grid[i][j-1]=='O'){
        grid[i][j-1]='@';
        solve1(grid,i,j-1);
    }
    if(i+1<grid.size() && grid[i+1][j]=='O'){
        grid[i+1][j]='@';
        solve1(grid,i+1,j);
    }
    if(j+1<grid[0].size() && grid[i][j+1]=='O'){
        grid[i][j+1]='@';
        solve1(grid,i,j+1);
    }
}
    void solve(vector<vector<char>>& grid) {
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]=='O'){
                grid[0][i]='@';
                solve1(grid,0,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]=='O'){
                grid[i][0]='@';
                solve1(grid,i,0);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[grid.size()-1][i]=='O'){
                grid[grid.size()-1][i]='@';
                solve1(grid,grid.size()-1,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][grid[0].size()-1]=='O'){
                grid[i][grid[0].size()-1]='@';
                solve1(grid,i,grid[0].size()-1);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[0].size();k++){
                if(grid[i][k]=='@'){
                    grid[i][k]='O';
                }
                else{
                    grid[i][k]='X';
                }
            }
        }
    }
};