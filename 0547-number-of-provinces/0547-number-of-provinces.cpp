class Solution {
public:
void solve(int node,vector<vector<int>>& isconnected,vector<bool>&visited){
    visited[node]=1;
    for(int i=0;i<isconnected.size();i++){
        if(i!=node && !visited[i]&& isconnected[node][i]==1){
            solve(i,isconnected,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        vector<bool>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                solve(i,isconnected,visited);
            }
        }
        return ans;
    }
};