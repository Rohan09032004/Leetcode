class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m=banned.size();
        set<int>r;
        for(int i=0;i<m;i++){
            r.insert(banned[i]);
        }
        int i=1;
        int ans=0;
        while(i<=n && maxSum>0){
            if(r.find(i)==r.end()){
                if(i<=maxSum){
                    maxSum-=i;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};