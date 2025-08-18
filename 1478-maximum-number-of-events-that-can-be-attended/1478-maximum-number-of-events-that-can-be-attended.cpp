class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int d=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,events[i][1]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int index=0;
        for(int i=1;i<=maxi;i++){
            while(index<n && events[index][0]<=i){
                pq.push({events[index][1],events[index][0]});
                index++;
            }
            while(!pq.empty() && pq.top().first<i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                d++;
            }
        }
        return d;
    }
};