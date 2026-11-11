
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], i});
        }

        sort(cars.begin(), cars.end());

        vector<double> time;

        for(int i = 0; i < n; i++) {
            int pos = cars[i].first;
            int idx = cars[i].second;

            double t = (double)(target - pos) / speed[idx];
            time.push_back(t);
        }

        int count = 0;
        double maxTime = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(time[i] > maxTime) {
                count++;
                maxTime = time[i];
            }
        }

        return count;
    }
};
