class Solution {
public:
    int consecutiveNumbersSum(int n) {
        long long int ans=0;
        long long int val=1;
        while((val*(val+1)/2)<=n){
            long long int rem=n-(val*(val+1)/2);
            if(rem%val==0){
                ans++;
            }
            val++;
        }
        return ans;
    }
};