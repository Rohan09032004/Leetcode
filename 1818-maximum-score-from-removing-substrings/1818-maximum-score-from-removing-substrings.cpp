class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        if (x >= y) {
            for (char c : s) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(c);
                }
            }
            string rem = "";
            while (!st.empty()) {
                rem += st.top();
                st.pop();
            }
            reverse(rem.begin(), rem.end());

            for (char c : rem) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(c);
                }
            }

        } else {
            // Remove "ba" first
            for (char c : s) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(c);
                }
            }
            
            string rem = "";
            while (!st.empty()) {
                rem += st.top();
                st.pop();
            }
            reverse(rem.begin(), rem.end());

            for (char c : rem) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(c);
                }
            }
        }

        return ans;
    }
};
