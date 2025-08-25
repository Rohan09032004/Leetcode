class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long int n=nums.size();
        long long int ans=1;
        int current=0;
        long long int j=0;
        for(long long int i=0;i<n;i++){
            while((current&nums[i])!=0){
                current^=nums[j];
                j++;
            }
            current=current|nums[i];
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};