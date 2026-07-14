class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        long long int ans=0;
        long long int ans1=0;
        ans1=ans1*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans1=ans1*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans1=ans1*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans=max(ans,ans1);
        cout<<ans1<<" ";
        long long int ans2=0;
        ans2=ans2*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans2=ans2*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans2=ans2*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans=max(ans,ans2);
        cout<<ans2<<" ";
        long long int ans3=0;
        ans3=ans3*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans3=ans3*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans3=ans3*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans=max(ans,ans3);
        cout<<ans3<<" ";
        long long int ans4=0;
        ans4=ans4*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans4=ans4*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans4=ans4*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans=max(ans,ans4);
        cout<<ans4<<" ";
        long long int ans5=0;
        ans5=ans5*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans5=ans5*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans5=ans5*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans=max(ans,ans5);
        cout<<ans5<<" ";
        long long int ans6=0;
        ans6=ans6*(pow(2,floor((log2(nums[2])+1))))+nums[2];
        ans6=ans6*(pow(2,floor((log2(nums[1])+1))))+nums[1];
        ans6=ans6*(pow(2,floor((log2(nums[0])+1))))+nums[0];
        ans=max(ans,ans6);
        cout<<ans6<<" ";
        return ans;
    }
};