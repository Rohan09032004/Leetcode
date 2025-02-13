class Solution {
public:
   bool isvowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>a(n);
        int pre=0;
        for(int i=0;i<n;i++){
            if(isvowel(words[i][0]) && isvowel(words[i][words[i].size()-1])){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
            a[i]=a[i]+pre;
            pre=a[i];
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                ans[i]=a[queries[i][1]];
            }
            else{
                ans[i]=a[queries[i][1]]-a[queries[i][0]-1];
            }
        }
        return ans;
    }
};