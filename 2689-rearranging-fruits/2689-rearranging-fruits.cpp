class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
    int n=basket1.size();
    map<int,int>c;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(basket1[i],mini);
        mini=min(basket2[i],mini);
        c[basket1[i]]++;
        c[basket2[i]]--;
    }
    for (auto &it : c) {
            if (abs(it.second) % 2 != 0) {
                return -1;
            }
        }
        long long ans = 0;
        int totalExtras = 0;
        for (auto &it : c) totalExtras += abs(it.second) / 2;
        totalExtras /= 2;
        for (auto &it : c) {
            int freq = abs(it.second) / 2;
            while (freq > 0 && totalExtras > 0) {
                ans += min(it.first, 2 * mini);
                freq--;
                totalExtras--;
            }
        }
    return ans;
    }
};