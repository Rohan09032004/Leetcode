class Solution {
public:
int dig(int n){
    string s=to_string(n);
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0');
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,int>roya;
        int ans=-1;
        for(int i=0;i<n;i++){
            long int count=dig(nums[i]);
            if(roya.count(count)){
                ans=max(ans,nums[i]+roya[count]);
                roya[count]=max(roya[count],nums[i]);
            }
            else{
                roya[count]=nums[i];
            }
        }
        return ans;
    }
};