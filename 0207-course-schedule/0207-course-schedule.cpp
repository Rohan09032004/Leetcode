class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prer) {
        vector<vector<int>>roya(n);
        for(int i=0;i<prer.size();i++){
            roya[prer[i][0]].push_back(prer[i][1]);
        }
        vector<int>degree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<roya[i].size();j++){
                degree[roya[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<roya[node].size();i++){
                degree[roya[node][i]]--;
                if(degree[roya[node][i]]==0){
                    q.push(roya[node][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(degree[i]>0){
                return false;
            }
        }
        return true;
    }
};