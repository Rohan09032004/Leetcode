class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>roya;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                roya[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto it:roya){
            int frequency=it.second;
            int val=(frequency)*(frequency-1)*(8)/2;
            ans+=val;
        }
        return ans;
    }
};