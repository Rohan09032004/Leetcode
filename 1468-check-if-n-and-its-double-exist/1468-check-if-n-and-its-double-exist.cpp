class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        set<int>roya;
        for(int i=0;i<n;i++){
            if(roya.find(2*arr[i])!=roya.end()){
                return true;
            }
            if(arr[i]%2==0 && (roya.find(arr[i]/2)!=roya.end())){
                return true;
            }
            roya.insert(arr[i]);
        }
        return false;
    }
};