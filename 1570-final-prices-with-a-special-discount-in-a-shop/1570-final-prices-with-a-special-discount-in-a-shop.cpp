class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>a;
        vector<int>ans=prices;
        for(int i=n-1;i>=0;i--){
            while(!a.empty() && a.top()>prices[i]){
                a.pop();
            }
            if(!a.empty()){
                ans[i]=prices[i]-a.top();
            }
            a.push(prices[i]);
        }
        return ans;
    }
};