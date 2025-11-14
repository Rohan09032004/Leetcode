class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        stack<int>s;
        for(int i=0;i<n;i++){ 
            while(!s.empty() && nums[i]<s.top()){
                s.pop();
            }
            if(s.empty() || nums[i]>s.top()){
                if(nums[i]==0){
                    continue;
                }
                ans++;
                s.push(nums[i]);
            }
        }
        return ans;
    }
};