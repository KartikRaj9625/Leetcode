class Solution {
public:
    bool sahi(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < have.size(); i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        vector<int> have(256, 0);
        vector<int> need(256, 0);

        int low = 0;
        int start = 0;
        int res = INT_MAX;

        for (char ch : t) {
            need[ch]++;
        }

        for (int high = 0; high < s.size(); high++) {
            have[s[high]]++;

            while (sahi(have, need)) {
                int len = high - low + 1;

                if (res > len) {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return res == INT_MAX ? "" : s.substr(start, res);
    }
};