class Solution {
public:
int solve(string& s, int k,char p){
    int n=s.size();
    int j=0;
    int countrequired=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(s[i]==p){
            countrequired++;
        }
        while(countrequired>k){
            if(s[j]==p){
                countrequired--;
            }
            j++;
        }
        maxi=max(maxi,i-j+1);
    }
    return maxi;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
    }
};