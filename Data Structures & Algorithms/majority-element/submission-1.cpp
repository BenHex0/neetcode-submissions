class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> keyToValue;
        unordered_map<int, int> valueToKey;

        for (int i = 0; i < nums.size(); i++) {
            keyToValue[nums[i]]++;
            int value = keyToValue[nums[i]];
            valueToKey[value] = nums[i];
        }

        vector<int> counts;
        for (auto& p : keyToValue) counts.push_back(p.second);
        sort(counts.begin(), counts.end());

        return valueToKey[counts.back()];
    }
};