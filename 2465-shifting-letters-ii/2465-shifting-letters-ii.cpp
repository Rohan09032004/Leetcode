class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>a(n,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                a[shifts[i][0]]--;
                if(shifts[i][1]!=n-1){
                    a[shifts[i][1]+1]++;
                }
            }
            if(shifts[i][2]==1){
                a[shifts[i][0]]++;
                if(shifts[i][1]!=n-1){
                    a[shifts[i][1]+1]--;
                }
            }
        }
        long long int pre=0;
        for(int i=0;i<n;i++){
            a[i]=a[i]+pre;
            pre=a[i];
            a[i]=(a[i]+(s[i]-'a'))%26;
            if(a[i]<0){
                a[i]+=26;
            }
            s[i]=a[i]+'a';
            cout<<a[i];
        }
        return s;
    }
};
