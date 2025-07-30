class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int temp=0;
        unordered_map<int,int>map;
        int sum=0;
         for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if(map.count(sum)){
                return true;
            }
            map[temp]++;
            temp=sum;
        }
        return false;
    }
};