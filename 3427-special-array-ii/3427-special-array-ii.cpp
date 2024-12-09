class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>a(n);
        a[0]=0;
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                count++;
                a[i]=count;
            }
            else{
                a[i]=count;
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            if(a[queries[i][0]]==a[queries[i][1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};