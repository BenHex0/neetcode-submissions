class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto p : count) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (!bucket[i].empty() && k > 0) {
                if (bucket[i].size() > 1) {
                    for (int n : bucket[i]) {
                        result.push_back(n);
                        k--;
                    }
                } else {
                    result.push_back(bucket[i][0]);
                    k--;
                }
            }
        }

        return result;
    }
};
