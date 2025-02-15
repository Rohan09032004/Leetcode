class Solution {
public:
set<int>roya;
void prime_number(){
    vector<int>prime(1001,1);
    // sieve of erotneses upto 1000 
        for (int i = 2; i * i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i<1000;i++){
        if(prime[i]){
            roya.insert(i);
        }
    }
}
    bool primeSubOperation(vector<int>& nums) {
        prime_number();
        int n=nums.size();
        int val=0;
        for(auto it:roya){
            if(it<nums[0]){
                val=it;
            }
            else{
                break;
            }
        }
        nums[0]=nums[0]-val;
        for(int i=1;i<nums.size();i++){
            val=nums[i]-(nums[i-1]);
            int number=0;
            for(auto it:roya){
                if(it<val){
                    number=it;
                }
                else{
                    break;
                }
            }
            nums[i]-=number;
            cout<<nums[i-1];
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }
};