class Solution {
public:
    long long findScore(vector<int>& nums) {
        int s=nums.size();
        vector<int>a(s,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i=0;i<s;i++){
            p.push({nums[i],i});
        }
        long long int sc=0;
        while(!p.empty()){
            long long int val=p.top().first;
            long long int ix=p.top().second;
            if(a[ix]==0){
                a[ix]=1;
                sc+=val;
                if(ix!=0){
                    a[ix-1]=1;
                }
                if(ix!=s-1){
                    a[ix+1]=1;
                }
            }
            p.pop();
        }
        return sc;
    }
};