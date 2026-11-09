class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        int hours = 0;
        for(int p : piles){
        hours += (p+k-1)/k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low + (high-low)/2;
            if(check(piles,h,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};