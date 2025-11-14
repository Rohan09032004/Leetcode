class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int ans=0;
        stack<int>s;
        int min1=0;
        for(int i=0;i<n;i++){ 
           if(s.empty()||target[i]>s.top()){
            if(!s.empty()){   
            ans+=target[i]-s.top();
            }
            else{
                ans+=target[i];
            }
            s.push(target[i]);
           }
           if(target[i]<s.top()){
            s.push(target[i]);
           }
        }
        return ans;
    }
};