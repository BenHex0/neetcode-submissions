class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro = 1;
        int zero = 0;
        for (int n : nums)
        {
            if (n == 0)
            {
                zero++;
                continue;
            }
            pro *= n;
        }

        vector<int> res;
        for (int n : nums)
        {
            if (n == 0)
            {
                res.push_back(zero > 1 ? 0 : pro);
                continue;
            }

            if (zero > 0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(pro / n);
            }
        }

        return res;
    }
};
