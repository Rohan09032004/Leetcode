class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i=i+2){
            if((s[i]-'0')^(s[i+1]-'0')){
                ans++;
            }
        }
        return ans;
    }
};