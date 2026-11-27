class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> map;
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            map[wordList[i]] = 1;
        }
        if (map.find(beginWord) == map.end())
            map[beginWord] = 1;

        if (map.find(endWord) == map.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        map.erase(beginWord);

        while (!q.empty()) {
            auto [str, val] = q.front();
            q.pop();

            if (str == endWord)
                return val;

            for (int i = 0; i < str.size(); i++) {
                char c = str[i];

                for (int j = 97; j <= 122; j++) {
                    if (c == j)
                        continue;

                    str[i] = j;
                    if (map.find(str) != map.end()) {
                        q.push({str, val + 1});
                        map.erase(str);
                    }
                }
                str[i] = c;
            }
        }
        return 0;
    }
};