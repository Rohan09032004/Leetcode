class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        double sum = 0;
        for(int i=0;i<k-1;i++){
            sum+=nums[i];
        }
        for(int i=k-1;i<nums.size();i++){
            sum+=nums[i];
            ans= max(ans,sum/k);
            sum-=nums[i-k+1];
        }
        return ans;
    }
};