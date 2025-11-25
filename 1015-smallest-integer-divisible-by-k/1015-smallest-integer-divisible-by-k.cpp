class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int val=0;
        for(int i=0;i<k;i++){
            val=val*10+1;
            if((val%k)==0){
                return i+1;
            }
            val=val%k;
        }
        return -1;
    }
};