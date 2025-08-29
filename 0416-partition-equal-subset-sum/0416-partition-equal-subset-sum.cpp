class Solution {
public:
bool solve(int currsum,vector<int>&nums,int index,int required,vector<vector<int>>&dp){
    if(currsum==required){
        return true;
    }
    if(currsum>required||index>=nums.size()){
        return false;
    }
    if(dp[index][currsum]!=-1){
        return dp[index][currsum];
    }
    return dp[index][currsum]=solve(currsum+nums[index],nums,index+1,required,dp)|solve(currsum,nums,index+1,required,dp);
}
    bool canPartition(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        bool result=solve(0,nums,0,sum/2,dp);
        return result;
    }
};