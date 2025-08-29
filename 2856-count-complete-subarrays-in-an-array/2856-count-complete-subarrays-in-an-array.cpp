class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int j=0;
        set<int>roya;
        for(int i=0;i<n;i++){
            roya.insert(nums[i]);
        }
        map<int,int>r;
        for(int i=0;i<n;i++){
            r[nums[i]]++;
            while(j<n && r.size()==roya.size()){
                ans+=(n-i);
                r[nums[j]]--;
                if(r[nums[j]]==0){
                    r.erase(nums[j]);
                }
                j++;
            }
        }
        return ans;
    }
};