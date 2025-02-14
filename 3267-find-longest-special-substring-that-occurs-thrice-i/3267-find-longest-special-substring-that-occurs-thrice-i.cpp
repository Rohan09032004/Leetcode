class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        for(int i=1;i<=n-2;i++){
            map<string,int>r;
            for(int j=0;j<n-i+1;j++){
                string little=s.substr(j,i);
                int flag=1;
                for(int i=0;i<little.size()-1;i++){
                    if(little[i]!=little[i+1]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                r[little]++;
                }
            }
            for(auto it:r){
                if(it.second>2){
                    ans=max(ans,i);
                }
            }
            if(ans<i){
                return ans;
            }
        }
        return ans;
    }
};