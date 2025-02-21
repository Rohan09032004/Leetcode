class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& matrices) {
        int n=matrices.size();
        int m=matrices[0].size();
        vector<vector<int>>ans(n,vector<int>(m,10000));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrices[i][j]==1){
                    ans[i][j]=0;
                    continue;
                }
                int top=10000;
                int bottom=10000;
                if(i-1>=0){
                    top=ans[i-1][j];
                }
                if(j-1>=0){
                    bottom=ans[i][j-1];
                }
                ans[i][j]=min(top,bottom)+1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrices[i][j]==1){
                    ans[i][j]=0;
                    continue;
                }
                int top=10000;
                int bottom=10000;
                if(i+1<n){
                    top=ans[i+1][j];
                }
                if(j+1<m){
                    bottom=ans[i][j+1];
                }
                ans[i][j]=min(ans[i][j],min(top,bottom)+1);
            }
        }
        return ans;
    }
};