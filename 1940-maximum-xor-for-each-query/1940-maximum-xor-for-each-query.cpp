class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        int j=n-1;
        int val=pow(2,maximumBit)-1;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=ans^val;
            ans^=nums[j];
            j--;
        }
        return result;
    }
};