class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int m=nums.size();
        if(k==1){
            return nums;
        }
        int count=1;
        vector<int>ans(m-k+1);
        for(int i=1;i<k-1;i++){
            if(nums[i]-nums[i-1]==1){
                count++;
            }
            else{
                count=1;
            }
        }
        for(int i=k-1;i<m;i++){
            if(nums[i]-nums[i-1]==1){
                count++;
            }
            else{
                count=1;
            }
            if(count>=k){
                ans[i-k+1]=nums[i];
            }
            else{
                ans[i-k+1]=-1;
            }
        }
        return ans;
    }
};