class Solution {
public:
int countbit(int i){
    int count=0;
    while(i>0){
        if(i&1){
            count++;
        }
        i=i>>1;
    }
    return count;
}
    bool canSortArray(vector<int>& nums) {
        vector<int>setbit(257,0);
        for(int i=1;i<257;i++){
            setbit[i]=countbit(i);
        }
        for(int i=1;i<nums.size();i++){
            int j=i;
            while(j>0 && nums[j]<nums[j-1]){
                if(setbit[nums[j]]==setbit[nums[j-1]]){
                swap(nums[j],nums[j-1]);
                j=j-1;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};