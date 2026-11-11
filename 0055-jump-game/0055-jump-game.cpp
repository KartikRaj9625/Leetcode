class Solution {
public:
    bool canJump(vector<int>& nums) {

        // int maxReach = 0;

        // for (int i = 0; i < nums.size(); i++) {
        //     if (i > maxReach)
        //         return false;
        //     maxReach = max(maxReach, i + nums[i]);
        //     if (maxReach >= nums.size() - 1)
        //         return true;
        // }

        // return true;
        int n = nums.size();
        int goal = n-1;
        for(int i = n-2; i>=0; i--){
            if(i+nums[i]>=goal){
                goal=i;
            }
        }
        return goal==0;
    }
};