class Solution {
public:

    void solve(int idx,
               vector<int>& candidates,
               int target,
               int sum,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        // Base Case
        if (idx == candidates.size()) {
            if (sum == target)
                ans.push_back(curr);
            return;
        }

        // Exclude current element
        solve(idx + 1, candidates,target, sum, curr, ans);

        // Include current element (can be taken multiple times)
        if (sum + candidates[idx] <= target) {
            curr.push_back(candidates[idx]);

            solve(idx,
                  candidates,
                  target,
                  sum + candidates[idx],
                  curr,
                  ans);

            curr.pop_back();   // Backtracking
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, 0, curr, ans);

        return ans;
    }
};