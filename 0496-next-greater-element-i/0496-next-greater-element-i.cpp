class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>stk;
        unordered_map<int,int>ans;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums2[i]>=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                ans[nums2[i]]=-1;
            }
            else{
                ans[nums2[i]]=stk.top();
            }
            stk.push(nums2[i]);
        }
        vector<int>roya(nums1.size());
        for(int i=0;i<nums1.size();i++){
            roya[i]=ans[nums1[i]];
        }
        return roya;
    }
};