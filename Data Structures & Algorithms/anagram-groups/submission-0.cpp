class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> countMap;

        for (char c : s) {
            countMap[c]++;
        }
        
        for (char c : t) {
            if (countMap.find(c) == countMap.end()) {
                return false;
            }
            countMap[c]--;
            if (countMap[c] == 0) {
                countMap.erase(c);
            }
        }
        
        return countMap.empty();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, bool> map;

        for (int i = 0; i < strs.size(); i++)
        {
            if (map[strs[i]])
                continue;
            vector<string> temp;

            for (int j = 0; j < strs.size(); j++)
            {
                if (isAnagram(strs[i], strs[j]))
                {
                    temp.push_back(strs[j]);
                    map[strs[j]] = true;
                }
            }
            result.push_back(temp);
        }

        return result;
    }

};
