class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long int n=nums.size();
        vector<long long>a(n,0);
        int val=0;
        for(int i=n-2;i>=0;i--){
            val=max(val,nums[i+1]);
            a[i]=val;
        }
        int i=0;
        int j=1;
        long long int maxi=0;
        while(i<n && j<n){
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