class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int ans=0;
        int current=0;
        map<int,int>a;
        int j=0;
        for(int i=0;i<n;i++){
            a[fruits[i]]++;
            while(a.size()>2){
                a[fruits[j]]--;
                if(a[fruits[j]]==0){
                    a.erase(fruits[j]);
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};