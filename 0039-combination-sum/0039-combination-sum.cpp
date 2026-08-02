class Solution {
public:
    void solve(int idx,
               vector<int>& candidates,
               int target,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        // Base Case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Not Take
        solve(idx + 1, candidates, target, curr, ans);

        // Take
        curr.push_back(candidates[idx]);

        solve(idx,
              candidates,
              target - candidates[idx],
              curr,
              ans);

        // Backtrack
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};