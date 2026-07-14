class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans=1;
        for(int i=2;i<=n;i++){
            long long int power=log2(i)+1;
            long long int multiplier=pow(2,power);
            ans=((ans*multiplier)%1000000007+i)%1000000007;
        }
        return ans;
    }
};