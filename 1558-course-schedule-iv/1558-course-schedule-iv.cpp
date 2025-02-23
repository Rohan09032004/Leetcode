class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> inDeg(numCourses,0);
        vector<int> adj[106];
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            inDeg[it[1]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        unordered_map<int,set<int>> parent;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                inDeg[it]--;
                for(auto p: parent[node]){
                    parent[it].insert(p);
                }
                parent[it].insert(node);
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            set<int> par=parent[queries[i][1]];
            bool possible=true;
            for(auto it:par){
                if(it==queries[i][0]){
                    ans.push_back(true);
                    possible=false;
                    break;
                }
            }
            if(possible)
                ans.push_back(false);
        }
        return ans;
    }
};