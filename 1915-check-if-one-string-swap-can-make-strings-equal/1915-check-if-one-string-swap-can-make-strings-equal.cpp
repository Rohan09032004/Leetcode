class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        vector<int>s;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                s.push_back(i);
            }
        }
        if(s.size()==0){
            return true;
        }
        if (s.size() == 2) {
            int i = s[0], j = s[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }
        return false;
    }
};