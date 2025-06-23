class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) {
    unordered_set<int> all;
    vector<int> cur, nxt;

    for (int x : a) {
        nxt.clear();
        nxt.push_back(x);
        for (int v : cur) {
            int nv = v | x;
            if (nxt.back() != nv) {
                nxt.push_back(nv);
            }
        }
        cur.swap(nxt);
        for (int v : cur) {
            all.insert(v);
        }
    }
    return all.size();
    }
};