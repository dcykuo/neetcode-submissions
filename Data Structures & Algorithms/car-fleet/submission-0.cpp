class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position (descending)
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for (auto& car : cars) {
            double time = (double)(target - car.first) / car.second;

            // Add the current car's arrival time
            st.push(time);

            // Merge with the fleet ahead if possible
            if (st.size() >= 2) {
                double current = st.top();
                st.pop();

                if (current > st.top()) {
                    st.push(current);
                }
            }
        }

        return st.size();
    }
};
