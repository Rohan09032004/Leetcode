class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      long long int ans=0;
      long long int n=nums.size();
      ans=n*(n-1)/2;
      map<long long int,long long int>r;
      for(int i=0;i<n;i++){
        nums[i]=nums[i]-i;
        r[nums[i]]++;
      }
      for(auto it:r){
        ans-=(it.second)*(it.second-1)/2;
      }
      return ans;
    }
};