class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int nas=0;
        int n=s.size();
        vector<int>first(26,-1);
        for(int i=n-1;i>=0;i--){
            first[s[i]-'a']=i;
        }
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++){
        set<int>roya;
            for(int j=first[i]+1;j<last[i];j++){
                roya.insert(s[j]-'a');
            }
            nas+=roya.size();
        }
        return nas;
    }
};