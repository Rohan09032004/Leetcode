class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int maxindex=0;
        int count=0;
        for(int i=0;i<n;i++){
            maxindex=arr[i];
            while(i<n && i<=maxindex){
                maxindex=max(maxindex,arr[i]);
                i++;
            }
            i--;
            count++;
        }
        return count;
    }
};