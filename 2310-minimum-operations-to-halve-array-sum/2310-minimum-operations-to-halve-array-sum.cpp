class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<long double>pq;
        long double sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        long double r=sum/2;
        int ans=0;
        while(true){
            long double val=pq.top();
            sum-=val/2;
            ans++;
            pq.pop();
            if(sum<=r){
                return ans;
            }
            pq.push(val/2);
        }
        return ans;
    }
};