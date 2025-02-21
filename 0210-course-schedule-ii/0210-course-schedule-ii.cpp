class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>roya(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            roya[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>degree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<roya[i].size();j++){
                degree[roya[i][j]]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<roya[node].size();i++){
                degree[roya[node][i]]--;
                if(degree[roya[node][i]]==0){
                    q.push(roya[node][i]);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(degree[i]>0){
                return { };
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};