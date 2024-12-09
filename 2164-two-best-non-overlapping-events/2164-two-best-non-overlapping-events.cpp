class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        map<int,int>a;
        sort(events.begin(),events.end());
        int maxi=events[n-1][2];
        for(int i=n-1;i>=0;i--){
            a[events[i][0]]=max(maxi,events[i][2]);
            maxi=max(maxi,events[i][2]);
        }
        int maxval=0;
        for(int i=0;i<n;i++){
            int ans=events[i][2];
            auto it = a.upper_bound(events[i][1]);
            if (it != a.end()) {
                ans += it->second;
            }

            maxval=max(maxval,ans);
        }
        return maxval;
    }
};