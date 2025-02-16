class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        sort(items.begin(),items.end());
        int pre=0;
        map<int,int>r;
        for(int i=0;i<n;i++){
            r[items[i][0]]=max(pre,items[i][1]);
            pre=r[items[i][0]];
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i]<items[0][0]){
                queries[i]=0;
            }
            else{
                auto it = r.lower_bound(queries[i]+1);

            if (it ==r.begin()){
             queries[i]=it->second;
            }
            else{
            it--;
            queries[i]= it->second;
            }
            }
        }
        return queries;
    }
};