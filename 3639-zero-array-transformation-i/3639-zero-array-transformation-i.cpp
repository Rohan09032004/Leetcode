class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>a(n,0);
        for(int i=0;i<queries.size();i++){
            a[queries[i][0]]++;
            if(queries[i][1]<n-1){
                a[queries[i][1]+1]--;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                a[i]+=a[i-1];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>a[i]){
                return false;
            }
        }
        return true;
    }
};