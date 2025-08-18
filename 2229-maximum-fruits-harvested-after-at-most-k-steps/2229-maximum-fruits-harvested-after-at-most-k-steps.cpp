class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxi = 0;
        int maxPos = fruits.back()[0];
        vector<int> presum(maxPos + 2, 0);

        int j = 0;
        for (int i = 0; i <= maxPos; i++) {
            if (j < n && fruits[j][0] == i) {
                presum[i] = fruits[j][1];
                j++;
            }
            if (i > 0) presum[i] += presum[i-1];
        }

        for (int j = 0; j <= k; j++) {
            int left = max(0, startPos - j);
            int right = min(maxPos, startPos + (k - 2*j));
            if (right >= left) {
                int curr = presum[right] - (left > 0 ? presum[left- 1] : 0);
                maxi = max(maxi, curr);
            }
            left = max(0, startPos - (k - 2*j));
            right = min(maxPos, startPos + j);
            if (right >= left) {
                int curr = presum[right] - (left > 0 ? presum[left - 1] : 0);
                maxi = max(maxi, curr);
            }
        }

        return maxi;
    }
};
