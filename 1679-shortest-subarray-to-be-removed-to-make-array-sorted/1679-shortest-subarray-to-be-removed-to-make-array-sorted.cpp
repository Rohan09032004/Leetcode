class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans1=1;
        int i=0;
        while(i<arr.size()-1 && arr[i]<=arr[i+1]){
            ans1++;
            i++;
        }
        int j=arr.size()-1;
        int ans=ans1;
        if(i==j){
            return 0;
        }
        while(i>=0 && arr[i]>arr[j]){
            i--;
            ans--;
        }
        j--;
        ans++;
        int ans3=ans;
        while(i>=0){
            while(arr[j]>=arr[i] && arr[j]<=arr[j+1]){
                j--;
                ans++;
                ans3=max(ans,ans3);
            }
            i--;
            ans--;
            ans3=max(ans,ans3);
        }
        j=arr.size()-1;
        int ans2=1;
        while(j>0 && arr[j]>=arr[j-1]){
            ans2++;
            j--;
        }
        return arr.size()-max(ans3,max(ans1,ans2));
    }
};