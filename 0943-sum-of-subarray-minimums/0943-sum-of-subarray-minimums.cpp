class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int n=arr.size();
        stack<pair<long long int,long long int>>st1,st2;
        vector<long int>ansl(n,-1),ansr(n,n);
        long long int ans=0;
        for(long long int i=n-1;i>=0;i--){
            while(!st1.empty()  &&  arr[i]<st1.top().first){
                st1.pop();
            }
            if(!st1.empty()){
                ansr[i]=st1.top().second;
            }
            st1.push({arr[i],i});
        }
        for(long long int i=0;i<n;i++){
            while(!st2.empty()  &&  arr[i]<=st2.top().first){
                st2.pop();
            }
            if(!st2.empty()){
                ansl[i]=st2.top().second;
            }
            st2.push({arr[i],i});
        }
        for(int i=0;i<n;i++){
            ans=(ans+(arr[i]*(i-ansl[i])*(ansr[i]-i))%1000000007)%1000000007;
        }
        return ans;
    }
};
