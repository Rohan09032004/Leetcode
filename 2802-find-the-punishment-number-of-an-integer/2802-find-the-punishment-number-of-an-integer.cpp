class Solution {
public:
 bool isPartitionSumValid(string& s, int index, int currentSum, int target) {
        if (index == s.length()) {
            return currentSum == target;
        }
        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');
            if (isPartitionSumValid(s, i + 1, currentSum + num, target)) {
                return true;
            }
        }
        return false;
    }
    bool punishment(int n) {
        string s=to_string(n*n);
        return isPartitionSumValid(s, 0, 0, n);
    }
vector<int>req;
void count(){
    req.resize(1001,0);
    for(int i=1;i<=1000;i++){
        if(punishment(i)){
            req[i]=1;
        }
    }
}
    int punishmentNumber(int n) {
        count();
        int ans=0;
        for(int i=1;i<=n;i++){
            if(req[i]==1){
                ans=ans+i*i;
            }
        }
        return ans;
    }
};