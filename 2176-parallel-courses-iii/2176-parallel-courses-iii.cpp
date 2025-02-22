class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>roya(n+1);
        vector<int>cost(n+1,0);
        for(int i=0;i<relations.size();i++){
            roya[relations[i][0]].push_back(relations[i][1]);
        }
        vector<int>degree(n+1,0);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<roya[i].size();j++){
                degree[roya[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<=n;i++){
            if(degree[i]==0 && i!=0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<roya[node].size();i++){
                cost[roya[node][i]] = max(cost[roya[node][i]], cost[node] + time[node - 1]);
                degree[roya[node][i]]--;
                if(degree[roya[node][i]]==0){
                    q.push(roya[node][i]);
                }
            }
        }
        int totaltime=0;
        for(int i=1;i<=n;i++){
            totaltime=max(totaltime,cost[i]+time[i-1]);
        }
        return totaltime;
    }
};