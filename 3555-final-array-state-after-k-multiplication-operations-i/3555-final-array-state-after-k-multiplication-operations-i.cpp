class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int val=pq.top().first;
            int index=pq.top().second;
            val*=multiplier;
            pq.pop();
            pq.push({val,index});
        }
        while(!pq.empty()){
            int val=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            nums[index]=val;
        }
        return nums;
    }
};