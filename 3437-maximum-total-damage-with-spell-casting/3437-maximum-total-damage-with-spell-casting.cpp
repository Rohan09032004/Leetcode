class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long n = power.size();
        map<int, int> mapp;

        for (int x : power)
            mapp[x]++;

        vector<pair<long long, long long>> values;
        for (auto &p : mapp)
            values.push_back({p.first, p.second});

        long long size = values.size();
        vector<long long> ans(size, 0);
        long long mx = 0;

        ans[0] = 1LL * values[0].first * values[0].second;

        for (int i = 1, j = 0; i < size; i++) {
            while (j < i && values[j].first < values[i].first - 2) {
                mx = max(mx, ans[j]);
                j++;
            }
            ans[i] = mx + 1LL * values[i].first * values[i].second;
        }

        long long finalAns = 0;
        for (int i = 0; i < size; i++) {
            finalAns = max(finalAns, ans[i]);
        }

        return finalAns;
    }
};
