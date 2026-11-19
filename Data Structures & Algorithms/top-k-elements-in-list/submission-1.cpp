class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // Step 1: count frequency
        for (int num : nums) {
            count[num]++;
        }

        // Step 2: copy to vector
        vector<pair<int, int>> freq;

        for (auto& p : count) {
            freq.push_back(p);
        }

        // Step 3: sort by frequency (descending)
        sort(freq.begin(), freq.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            })

        // Step 4: Get top k elements
        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }

        return result;
    }
};
