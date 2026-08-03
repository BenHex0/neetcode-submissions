class Solution {
public:

    string encode(vector<string>& strs) {
        string str;

        for (string s : strs)
        {
            str += s;
            str += "-#-";
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        string temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-' && s[i + 1] == '#' && s[i + 2] == '-')
            {
                strs.push_back(temp);
                temp = "";
                i += 2;
            }
            else
            {
                temp += s[i];
            }
        }

        return strs;
    }
};
