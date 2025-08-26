class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>stk;
        vector<int>ans(n,0);
        for(int i=n-1;i>-1;i--){
            while(!stk.empty() && temperatures[i]>=stk.top().first){
                stk.pop();
            }
            if(stk.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=stk.top().second-i;
            }
            stk.push({temperatures[i],i});
        }
        return ans;
    }
};