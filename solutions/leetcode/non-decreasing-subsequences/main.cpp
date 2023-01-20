class Solution {
    char delimiter = '_';

    string encode(vector<int> vec) {
        string s;
        for (int v : vec) s += to_string(v) + delimiter;
        return s;
    }

    vector<int> decode(string s) {
        vector<int> vec;
        stringstream ss(s);
        string w;
        while (getline(ss, w, delimiter)) {
            vec.push_back(stoi(w));
        }
        return vec;
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<string> sub;
        vector<int> curr;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == nums.size()) return;

            dfs(i + 1);

            if (!curr.empty() && curr.back() > nums[i]) return;

            curr.push_back(nums[i]);
            if (curr.size() >= 2) sub.insert(encode(curr));

            dfs(i + 1);
            curr.pop_back();
        };

        dfs(0);

        vector<vector<int>> result;
        for (string s : sub) {
            cout << s << "\n";
            result.push_back(decode(s));
        }

        return result;
    }
};
