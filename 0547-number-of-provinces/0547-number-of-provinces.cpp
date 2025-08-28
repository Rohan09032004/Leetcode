class Solution {
public:
void dfs(int nodel, vector<bool>&visit,vector<vector<int>>&adjl){
    visit[nodel]=1;
    for(int i=0;i<adjl[nodel].size();i++){
        if(!visit[adjl[nodel][i]]){
            dfs(adjl[nodel][i],visit,adjl);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjl(n);
        vector<bool>visit(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                ans++;
                dfs(i,visit,adjl);
            }
        }
        return ans;
    }
};