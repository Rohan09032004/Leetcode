class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int nt=0;
        int st=0;
        int wt=0;
        int et=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                nt++;
            }
            else if(s[i]=='E'){
                et++;
            }
            else if(s[i]=='S'){
                st++;
            }
            else{
                wt++;
            }
            int horimax=max(et,wt);
            int horimin=min(et,wt);
            int vertimax=max(nt,st);
            int vertimin=min(nt,st);
            int val=horimax+vertimax+min(k,horimin+vertimin)-max(0,horimin+vertimin-k);
            ans=max(val,ans);
        }
        return ans;
    }
};