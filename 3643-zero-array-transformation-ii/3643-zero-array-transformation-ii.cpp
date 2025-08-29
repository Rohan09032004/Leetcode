class Solution {
public:
bool check(vector<int>&nums,vector<vector<int>>&queries,int k){
    int n=nums.size();
        vector<int>a(n,0);
        for(int i=0;i<k;i++){
            a[queries[i][0]]+=queries[i][2];
            if(queries[i][1]<n-1){
                a[queries[i][1]+1]-=queries[i][2];
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0;
        int high=queries.size();
        int ans=-1;
        while(low<=high){
            int k=(low+high)/2;
            if(check(nums,queries,k)){
                ans=k;
                high=k-1;
            }
            else{
                low=k+1;
            }
        }
        return ans;
    }
};