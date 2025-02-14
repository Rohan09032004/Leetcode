class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>a(100001,0);
        for(int i=0;i<n;i++){
            if(nums[i]-k<1){
                a[0]++;
            }
            else{
                a[nums[i]-k]++;
            }
            if(nums[i]+k<100000){
                a[nums[i]+k+1]--;
            }
        }
        int maxiii=a[0];
        for(int i=1;i<100001;i++){
            a[i]+=a[i-1];
            maxiii=max(maxiii,a[i]);
        }
        return maxiii;
    }
};