class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n=nums.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>p;
        long long minimum=INT_MAX;
        long long prefixsum=0;
        p.push({0,-1});
        for(long long i=0;i<n;i++){
            prefixsum+=nums[i];
            while(!p.empty() && prefixsum-k>=p.top().first){
                int j=p.top().second;
                minimum=min(minimum,i-j);
                p.pop();
            }
            p.push({prefixsum,i});
        }
        if(minimum==INT_MAX)return -1;
        return minimum;
    }
};
// edge case [84,-37,32,40,95] k=167
//here negative number restricts 