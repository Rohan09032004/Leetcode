class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int maxi=INT_MIN;
        reverse(energy.begin(),energy.end());
        for(int i=0;i<k;i++){
        int sum=0;
        for(int j=i;j<n;j+=k){
            sum+=energy[j];
            maxi=max(maxi,sum);
        }
        }
        return maxi;
    }
};