class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0;
        int j=0;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]^colors[(i-1)%n]!=1){
                j=i;
            }
            if(i-j+1==k){
                ans++;
                j++;
            }
        }
        return ans;
    }
};