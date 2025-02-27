class Solution {
public:
int solve(int n,int mid,vector<int>& weights){
    int sum=0;
    int days=1;
    for(int i=0;i<n;i++){
        if(weights[i]+sum<=mid){
            sum+=weights[i];
        }
        else{
            i--;
            sum=0;
            days++;
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        int ans=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(n,mid,weights)<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};