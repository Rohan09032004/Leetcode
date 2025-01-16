class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int last=INT_MIN;
        int mid=nums[n-1];
        stack<int>st;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<last && last<mid){
                return true;
            }
            if(nums[i]>=mid){
                st.push(mid);
                mid=nums[i];
                while(!st.empty() && st.top()<mid){
                    last=st.top();
                    st.pop();
                }
            }
            if(nums[i]<mid && nums[i]>last){
                st.push(mid);
                mid=nums[i];
            }
        }
        return false;
    }
};