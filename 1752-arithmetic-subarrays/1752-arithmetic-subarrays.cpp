class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool>result(m,true);
        for(int i=0;i<m;i++){
            int size=r[i]-l[i]+1;
            if(size<2){
                result[i]=false;
                continue;
            }
            vector<int>ans(r[i]-l[i]+1);
            for(int j=l[i];j<=r[i];j++){
                ans[j-l[i]]=nums[j];
            }
            sort(ans.begin(),ans.end());
            for(int o=1;o<ans.size()-1;o++){
            if(ans[o]-ans[o-1]!=ans[o+1]-ans[o]){
                result[i]=false;
                break;
            }
            }
            if(result[i]==false){
            continue;
            }
        }
        return result;
    }
};