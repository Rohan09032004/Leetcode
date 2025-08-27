class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        long long int n=nums.size();
        stack<pair<long long int,long long int>>st1,st2;
        vector<long long int>ansl(n,-1),ansr(n,n);
        long long int ans=-1;
        vector<long long int>presum(n,0);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=nums[i]+presum[i-1];
        }
        for(long long int i=n-1;i>=0;i--){
            while(!st1.empty()  &&  nums[i]<=st1.top().first){
                st1.pop();
            }
            if(!st1.empty()){
                ansr[i]=st1.top().second;
            }
            st1.push({nums[i],i});
        }
        for(long long int i=0;i<n;i++){
            while(!st2.empty()  &&  nums[i]<=st2.top().first){
                st2.pop();
            }
            if(!st2.empty()){
                ansl[i]=st2.top().second;
            }
            st2.push({nums[i],i});
        }
        for(long long int i=0;i<n;i++){
            long long size=ansr[i]-ansl[i]-1;
            if(nums[i]>(threshold/size)){
                return size;
            }
        }
        return ans;
    }
};