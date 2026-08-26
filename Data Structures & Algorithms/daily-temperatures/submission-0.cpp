class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<pair<int, int>> st;
        vector<int> temp(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                auto t = st.top();
                int day = abs(t.second - i);
                temp[t.second] = day;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return temp;
    }
};
