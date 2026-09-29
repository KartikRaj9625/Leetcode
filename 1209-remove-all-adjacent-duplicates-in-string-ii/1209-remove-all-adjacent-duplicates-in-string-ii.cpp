class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push({s[i], 1});
                continue;
            }
            if (st.top().first != s[i]) {
                st.push({s[i], 1});
                continue;
            }
            if (st.top().second < (k - 1)) {
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second + 1});
                continue;
            }
            st.pop(); //removing pair
        }
        string res = "";
        while (!st.empty()) {
            pair<char, int> p = st.top();
            st.pop();
            while (p.second--) {
                res.push_back(p.first);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};