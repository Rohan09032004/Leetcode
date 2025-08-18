class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>a(26,0),seen(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']=i;
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && s[i]<st.top() && a[st.top()-'a']>i && seen[s[i]-'a']==0){
                seen[st.top()-'a']=0;
                st.pop();
            }
            if(!seen[s[i]-'a']){
                seen[s[i]-'a']=1;
            st.push(s[i]);
            }
        }
        string p;
        while(!st.empty()){
            p+=st.top();
            st.pop();
        }
        reverse(p.begin(),p.end());
        return p;
    }
};