class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (const string& s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // find #
            while (s[j] != '#') {
                j++;
            }

            // get string length
            int len = stoi(s.substr(i,j-1));

            // get string
            string word = s.substr(j+1, len);
            result.push_back(word);
            
            // move to the next string
            i = j + 1 + len;
        }

        return result
    }
};
