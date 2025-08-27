class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long int n=heights.size();
        stack<pair<long long int,long long int>>st1,st2;
        vector<long int>ansl(n,-1),ansr(n,n);
        long long int ans=0;
        for(long long int i=n-1;i>=0;i--){
            while(!st1.empty()  &&  heights[i]<st1.top().first){
                st1.pop();
            }
            if(!st1.empty()){
                ansr[i]=st1.top().second;
            }
            st1.push({heights[i],i});
        }
        for(long long int i=0;i<n;i++){
            while(!st2.empty()  &&  heights[i]<=st2.top().first){
                st2.pop();
            }
            if(!st2.empty()){
                ansl[i]=st2.top().second;
            }
            st2.push({heights[i],i});
        }
        for(long long int i=0;i<n;i++){
            long long int currar=(heights[i]*((ansr[i]-i)+(i-ansl[i])-1));
            cout<<(i-ansl[i])<<" "<<(ansr[i]-i)<<endl;
            ans=max(currar,ans);
        }
        return ans;
    }
};