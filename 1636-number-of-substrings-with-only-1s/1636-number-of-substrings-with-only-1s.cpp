class Solution {
public:
    int numSub(string s) {
        long long int n=s.size();
        long long int ans=0;
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            else{
                ans=(ans+(cnt*(cnt+1)/2)%1000000007)%1000000007;
                cnt=0;
            }
        }
        ans=(ans+(cnt*(cnt+1)/2)%1000000007)%1000000007;
        return ans;
    }
};