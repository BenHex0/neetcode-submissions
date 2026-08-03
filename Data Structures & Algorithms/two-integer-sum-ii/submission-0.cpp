class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = 0, l = numbers.size() - 1;
        vector<int> res;
        while (true)
        {
            if (numbers[r] + numbers[l] > target)
            {
                l--;
            }
            else if (numbers[r] + numbers[l] < target)
            {
                r++;
            }
            else
            {
                res.push_back(r + 1);
                res.push_back(l + 1);
                break;
            }
        }
        return res;
    }
};
