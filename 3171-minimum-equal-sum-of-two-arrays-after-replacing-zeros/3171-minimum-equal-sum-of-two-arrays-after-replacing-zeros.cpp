class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        long long int num1=0;
        long long int num2=0;
        long long int num1zero=0;
        long long int num2zero=0;
        for(int i=0;i<nums1.size();i++){
            num1+=nums1[i];
            if(nums1[i]==0){
                num1zero++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            num2+=nums2[i];
            if(nums2[i]==0){
                num2zero++;
            }
        }
        if(num1zero>0 && num2zero>0){
            return max(num1+num1zero,num2+num2zero);
        }
        else if(num1zero+num2zero==0){
            if(num1==num2){
                return num1;
            }
            return -1;
        }
        else{
            if(num1zero==0){
                if(num2+num2zero<=num1){
                    return num1;
                }
                return -1;
            }
            else{
                if(num1+num1zero<=num2){
                    return num2;
                }
                return -1;
            }
        }
        return 0;
    }
};