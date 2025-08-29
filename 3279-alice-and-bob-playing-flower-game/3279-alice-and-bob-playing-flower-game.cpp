class Solution {
public:
    long long flowerGame(int n, int m) {
        long long int ans=0;
        for(int i=1;i<=n;i++){
            if(i%2){
                ans=ans+(m/2);
            }
            else{
                ans=ans+((m+1)/2);
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};