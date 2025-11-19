class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
    int n=nums.size();
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(nums[i]);
    }
    while(true){
        if(s.find(original)==s.end()){
            break;
        }
        else{
            original*=2;
        }
    }
    return original;
    }
};