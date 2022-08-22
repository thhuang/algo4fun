class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int v : nums) strs.push_back(to_string(v));

        sort(strs.begin(), strs.end(),
             [](const string& sa, const string& sb) -> bool {
                 return sa + sb > sb + sa;
             });

        string result;
        for (const string& s : strs) result += s;

        if (result.front() == '0') return "0";
        return result;
    }
};
