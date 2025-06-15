class Solution {
public:
    int integerReplacement(long long int n) {
        int count=0;
    while(n>1){
           if(n%2==0){
            n=n/2;
            count++;
        }
        else{
            if((n-1)%4==0 ||  n==3){
                n=n-1;
                count++;
            }
            else{
                n=n+1;
                count++;
            }
        }
    }
    return count;
    }
};