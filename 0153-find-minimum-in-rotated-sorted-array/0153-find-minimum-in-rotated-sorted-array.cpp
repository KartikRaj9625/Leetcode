class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int guess = low + ((high-low)/2);
            if(nums[guess]>nums[n-1]){
                low = guess+1;
            }else{
                res = nums[guess];
                high = guess-1;
            }
            
        }
        return res;
     }
};