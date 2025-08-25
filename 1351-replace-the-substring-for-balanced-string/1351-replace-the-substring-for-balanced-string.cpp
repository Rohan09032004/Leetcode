class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        int q=0;
        int w=0;
        int r=0;
        int e=0;
        for(int  i=0;i<n;i++){
            if(s[i]=='Q'){
                q++;
            }
            if(s[i]=='W'){
                w++;
            }
            if(s[i]=='E'){
                e++;
            }
            if(s[i]=='R'){
                r++;
            }
        }
        int ans=n;
        q=max(q-(n/4),0);
        w=max(w-(n/4),0);
        e=max(e-(n/4),0);
        r=max(r-(n/4),0);
        int k=0;
        for(int i=0;i<n;i++){
            if(s[i]=='Q') q--;
            if(s[i]=='W') w--;
            if(s[i]=='E') e--;
            if(s[i]=='R') r--;
            while(k<n && q<=0 && w<=0 && e<=0 && r<=0){
                ans = min(ans, i - k + 1);

                if(s[k]=='Q') q++;
                if(s[k]=='W') w++;
                if(s[k]=='E') e++;
                if(s[k]=='R') r++;
                k++;
            }
        }
        return ans;
    }
};