class Solution {
public:
void solve(vector<vector<int>>&grid,int i,int j){
    if(i-1>=0 && grid[i-1][j]==1){
        grid[i-1][j]=0;
        solve(grid,i-1,j);
    }
    if(j-1>=0 && grid[i][j-1]==1){
        grid[i][j-1]=0;
        solve(grid,i,j-1);
    }
    if(i+1<grid.size() && grid[i+1][j]==1){
        grid[i+1][j]=0;
        solve(grid,i+1,j);
    }
    if(j+1<grid[0].size() && grid[i][j+1]==1){
        grid[i][j+1]=0;
        solve(grid,i,j+1);
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                grid[0][i]=0;
                solve(grid,0,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                solve(grid,i,0);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[grid.size()-1][i]==1){
                grid[grid.size()-1][i]=0;
                solve(grid,grid.size()-1,i);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][grid[0].size()-1]==1){
                grid[i][grid[0].size()-1]=0;
                solve(grid,i,grid[0].size()-1);
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[0].size();k++){
                if(grid[i][k]==1){
                    ans++;
                }
            }
        }
    return ans;
    }
};