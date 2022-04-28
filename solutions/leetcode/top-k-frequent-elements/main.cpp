class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> rank;
        vector<array<int, 2>> freq;
        for (int v : nums) {
            if (!rank.count(v)) {
                rank.insert({v, freq.size()});
                freq.push_back({v, 1});
                continue;
            }

            int i = rank.at(v);
            ++freq[i][1];
            while (i > 0 && freq[i - 1][1] < freq[i][1]) {
                swap(freq[i - 1], freq[i]);
                rank[freq[i - 1][0]] = i - 1;
                rank[freq[i][0]] = i;
                --i;
            }
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) result.push_back(freq[i][0]);

        return result;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (int v : nums) ++num_freq[v];

        priority_queue<array<int, 2>> q;
        for (auto p : num_freq) q.push({p.second, p.first});

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(q.top()[1]);
            q.pop();
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (int v : nums) ++num_freq[v];

        vector<int> result;
        for (auto p : num_freq) result.push_back(p.first);

        auto partition = [&](int i) -> int {
            int target = num_freq[result[i]];
            int l = 0, r = result.size() - 1;
            int p = 0;
            while (p <= r) {
                int x = num_freq[result[p]];
                if (x == target) {
                    ++p;
                } else if (x > target) {
                    swap(result[l], result[p]);
                    ++l, ++p;
                } else {
                    swap(result[r], result[p]);
                    --r;
                }
            }

            return p - 1;
        };

        random_device rd;
        default_random_engine gen(rd());
        int l = 0, r = result.size() - 1;
        while (true) {
            int i = uniform_int_distribution<int>(l, r)(gen);
            i = partition(i);
            if (i == k - 1) break;
            if (i < k - 1) {
                l = i + 1;
            } else {
                r = i - 1;
            }
        }

        result.erase(result.begin() + k, result.end());

        return result;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        vector<unordered_set<int>> freq_num(1);
        for (int v : nums) {
            auto it = num_freq.find(v);
            if (it == num_freq.end()) {
                num_freq[v] = 1;
            } else {
                freq_num[it->second++].erase(v);
            }
            int freq = num_freq[v];
            if (freq == freq_num.size()) freq_num.push_back({});
            freq_num[freq].insert(v);
        }

        vector<int> result;
        for (int f = freq_num.size() - 1; result.size() < k; --f) {
            for (int v : freq_num[f]) result.push_back(v);
        }

        return result;
    }
};
