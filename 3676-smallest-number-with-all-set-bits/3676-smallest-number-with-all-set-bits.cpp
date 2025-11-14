class Solution {
public:
    int smallestNumber(int n) {
        if(n&(n-1)==0){
            return n;
        }
        else {
            int digit=log2(n)+1;
            int ans1=pow(2,digit);
            int ans=ans1-1;
            return ans;
        }
    }
};