class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) {
    unordered_set<int> all;
    set<int> cur, nxt;

    for (int x : a) {
        nxt.clear();
        nxt.insert(x);
        for (int v : cur) {
        int nv = v | x;
        nxt.insert(nv);
        }
        cur=nxt;
        for (int v : cur) {
            all.insert(v);
        }
    }
    return all.size();
    }
};