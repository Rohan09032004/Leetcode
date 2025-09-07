class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        int n=nums.size(); 
        //intitially sare elements ko map mein store krke true mark kr diya
        for(int i = 0; i<n;i++){
            map[nums[i]] = true;
        }
        // yhs agar ith index wwale number ka preceding present hai toh us no. ko false mark kr diya bcoz we not check longest sequence for this number as its preceding exits (indicates ki yeah phele se hi kisi sequence ka part hai)
        for(int i=0;i<n;i++){
            if(map.count(nums[i]-1)){
                map[nums[i]]=false;
            }
        }
        int maximum=0;
        for(int i=0;i<n;i++){
            int count=1,j=1;
            if(map[nums[i]]==true){//unhi ke liye check krenge jinka preending nhi hai such that it ensures ki yha se longest sequence start hue hai
                 while(map.count(nums[i]+j) > 0){//sare consecutive count lr liye
                    j++;
                    count++;
                }

             maximum=max(count,maximum);
            }   
        }
        return maximum;
    }
};