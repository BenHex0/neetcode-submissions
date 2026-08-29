class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>,
                       greater<pair<int, vector<vector<int>>>>>
            minHeap;

        for (auto point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];

            minHeap.push({distance, {{point[0], point[1]}}});
        }

        vector<vector<int>> res;

        while (k > 0) {
            res.push_back(minHeap.top().second[0]);

            minHeap.pop();
            k--;
        }

        return res;
    }
};
