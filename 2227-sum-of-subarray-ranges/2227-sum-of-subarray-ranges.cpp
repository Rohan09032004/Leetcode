class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long int n=arr.size();
        stack<pair<long long int,long long int>>st1,st2;
        vector<long int>ansl(n,-1),ansr(n,n);
        long long int minans=0;
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
            minans=minans+(arr[i]*(i-ansl[i])*(ansr[i]-i));
        }
        stack<pair<long long int,long long int>>st3,st4;
        vector<long int>ansleft(n,-1),ansright(n,n);
        long long int maxans=0;
        for(long long int i=n-1;i>=0;i--){
            while(!st3.empty()  &&  arr[i]>st3.top().first){
                st3.pop();
            }
            if(!st3.empty()){
                ansright[i]=st3.top().second;
            }
            st3.push({arr[i],i});
        }
        for(long long int i=0;i<n;i++){
            while(!st4.empty()  &&  arr[i]>=st4.top().first){
                st4.pop();
            }
            if(!st4.empty()){
                ansleft[i]=st4.top().second;
            }
            st4.push({arr[i],i});
        }
        for(int i=0;i<n;i++){
            maxans=maxans+(arr[i]*(i-ansleft[i])*(ansright[i]-i));
        }
        return maxans-minans;
    }
};