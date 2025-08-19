class Solution {
public:
    long long zeroFilledSubarray(vector<int>& prices) {
        int n=prices.size();
        int j=0;
        long long total=0;
        for(int i=0;i<n;i++){
            if(prices[i]!=0){
                j=i+1;
            }
            else{
            total+=(i-j+1);
            }
        }
        return total;
    }
};