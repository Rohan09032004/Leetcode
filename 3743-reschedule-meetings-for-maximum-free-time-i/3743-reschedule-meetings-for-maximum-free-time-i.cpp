class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>ans;
        ans.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            ans.push_back(startTime[i]-endTime[i-1]);
        }
        ans.push_back(eventTime-endTime[n-1]);
        int res=0;
        int j=0;
        int maxi=0;
        for(int i=0;i<ans.size();i++){
            if(i-j<k){
                res+=ans[i];
            }
            else{
                res+=ans[i];
                maxi=max(maxi,res);
                res-=ans[j];
                j++;
            }
        }
        return maxi;
    }
};