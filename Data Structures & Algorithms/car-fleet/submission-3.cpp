class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for (auto c : cars) {
            st.push((double)(target - c.first) / c.second);
            if (st.size() >= 2) {
                double a = st.top();
                st.pop();
                double b = st.top();
                if (a <= b)
                    continue;
                else
                    st.push(a);
            }
        }

        return st.size();
    }
};
