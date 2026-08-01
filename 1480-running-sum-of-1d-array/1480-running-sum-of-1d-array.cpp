class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        for(int i = 1; i<n;i++){
            int x = ans[i-1]+ nums[i];
            ans.push_back(x);
        }
        return ans;
    }
};