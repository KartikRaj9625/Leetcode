class Solution {
public:
void solve(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
 if(idx == nums.size()){
    ans.push_back(curr);
    return;
 }
 solve(idx+1, curr,ans,nums);

 curr.push_back(nums[idx]);
 solve(idx+1, curr,ans,nums);
 curr.pop_back();

 return;

}


    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0,curr,ans ,nums);
        return ans;

    }
};