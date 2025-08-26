class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        set<int>a;
        set<int>b;
        set<int>c;
        for(int i=0;i<nums2.size();i++){
            a.insert(nums1[i]);
            b.insert(nums2[i]);
            c.insert(nums1[i]);
            c.insert(nums2[i]);
        }
        int common=a.size()+b.size()-c.size();
        int unique1=a.size()-common;
        int unique2=b.size()-common;
        cout<<common<<" ";
        int ans=min(n/2,unique1)+min(n/2,unique2)+common;
        ans=min(ans,n);
        return ans;
    }
};