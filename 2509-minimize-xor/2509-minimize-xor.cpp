class Solution {
public:
int count_set_bit(int n){
    int ans=0;
    while(n>0){
        if((n&1)==1){
            ans++;
        }
        n/=2;
    }
    return ans;
}
    int minimizeXor(int num1, int num2) {
        int v1=count_set_bit(num1);
        int v2=count_set_bit(num2);
        if(v1==v2){
            return num1;
        }
        else if(v2<v1){
            int i=v1-v2;
            int j=0;
            while(i){
                if(num1&(1<<j)){
                    num1&=~(1<<j);
                    i--;
                }
                j++;
            }
            return num1;
        }
        else{
            int i=v2-v1;
            int j=0;
            for (int j = 0; j < 32 &&  i > 0; j++) {
                if ((num1 & (1 << j)) == 0) {
                    num1 |= (1 << j);
                    i--;
                }
            }
            return num1;
        }
        return num1;
    }
};