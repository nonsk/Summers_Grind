class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int, priority_queue<int>> buckets;
        int n = limit.size();
        for (int i = 0; i < n; i++) {
            buckets[limit[i]].push(value[i]);
        }
        long long ans = 0;
        for (auto &it : buckets) {
            for (int j = 0; j < it.first && !it.second.empty(); j++) {
                    ans += it.second.top();
                    it.second.pop();
            }
        }
        return ans;
    }
};