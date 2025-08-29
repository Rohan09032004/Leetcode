class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long>a(nums.size(),0);
        int val=0;
        for(int i=nums.size()-2;i>=0;i--){
            val=max(val,nums[i+1]);
            a[i]=val;
        }
        int i=0;
        int j=1;
        long long int maxi=0;
        while(j<nums.size()){
            if(nums[j]>nums[i]){
                i=j;
                j++;
            }
            else{
                maxi=max(maxi,(nums[i]-nums[j])*a[j]);
                j++;
            }
        }
        return maxi;
    }
};