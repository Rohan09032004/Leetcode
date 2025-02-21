class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        int t=0;
        while(!que.empty()){
            int s=que.size();
            for(int i=0;i<s;i++){
            int row=que.front().first;
            int col=que.front().second;
            que.pop();
            if(row-1>=0 && grid[row-1][col]==1){
                que.push({row-1,col});
                grid[row-1][col]=2;
            }
            if(col-1>=0 && grid[row][col-1]==1){
                que.push({row,col-1});
                grid[row][col-1]=2;
            }
            if(row+1<n && grid[row+1][col]==1){
                que.push({row+1,col});
                grid[row+1][col]=2;
            }
            if(col+1<m && grid[row][col+1]==1){
                que.push({row,col+1});
                grid[row][col+1]=2;
            }
            }
            if(!que.empty()){
                t++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};