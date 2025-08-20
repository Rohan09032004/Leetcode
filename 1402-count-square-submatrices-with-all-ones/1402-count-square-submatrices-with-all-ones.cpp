class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>a(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    if(i>0 && j>0){
                        a[i][j]=min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]))+1;
                    }
                    else{
                        a[i][j]=1;
                    }
                }
                ans+=a[i][j];
            }
        }
        return ans;
    }
};