class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int val=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                val++;
            }
            else{
                ans=max(val,ans);
                val=1;
            }
        }
        ans=max(val,ans);
        val=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                val++;
            }
            else{
                ans=max(val,ans);
                val=1;
            }
        }
        return max(val,ans);
    }
};