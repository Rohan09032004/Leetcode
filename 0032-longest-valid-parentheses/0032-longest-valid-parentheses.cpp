class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>a(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    a[st.top()]=1;
                    a[i]=1;
                    st.pop();
                }
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};