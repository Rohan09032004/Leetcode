class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long long int cnt=0;
        map<long long int,long long int>roya;
        int j=0;
        long long int ans=0;
        for(int i=0;i<n;i++){
            roya[nums[i]]++;
            cnt+=(roya[nums[i]]-1);
            while(j<n && cnt>=k){
                ans+=(n-i);
                roya[nums[j]]--;
                cnt-=roya[nums[j]];
                j++;
            }
        }
        return ans;
    }
};