class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int sp=grid[sr][sc];
        queue<pair<int,int>>que;
        que.push({sr,sc});
        if(grid[sr][sc]==color){
            return grid;
        }
        grid[sr][sc]=color;
        while(!que.empty()){
            int s=que.size();
            for(int i=0;i<s;i++){
            int row=que.front().first;
            int col=que.front().second;
            que.pop();
            if(row-1>=0 && grid[row-1][col]==sp){
                que.push({row-1,col});
                grid[row-1][col]=color;
            }
            if(col-1>=0 && grid[row][col-1]==sp){
                que.push({row,col-1});
                grid[row][col-1]=color;
            }
            if(row+1<n && grid[row+1][col]==sp){
                que.push({row+1,col});
                grid[row+1][col]=color;
            }
            if(col+1<m && grid[row][col+1]==sp){
                que.push({row,col+1});
                grid[row][col+1]=color;
            }
            }
        }
        return grid;
    }
};